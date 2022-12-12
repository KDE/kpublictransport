/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

package org.kde.publictransport.onboard;

import android.content.*;
import android.location.LocationManager;
import android.net.*;
import android.net.wifi.*;
import android.os.Build;
import android.util.Log;

/** Java side of the Android implementation of WifiMonitor. */
public class WifiMonitor extends BroadcastReceiver
{
    private static final String TAG = "org.kde.publictransport.onboard";

    private static final int NOT_AVAILABLE = 0;
    private static final int AVAILABLE = 1;
    private static final int NOT_ENABLED = 2;
    private static final int NO_PERMISSION = 3;

    public WifiMonitor(Context context)
    {
        Log.d(TAG, "WifiMonitor ctor");
        m_context = context;
        checkStatus();

        IntentFilter intentFilter = new IntentFilter(WifiManager.NETWORK_STATE_CHANGED_ACTION);
        context.getApplicationContext().registerReceiver(this, intentFilter);

        intentFilter = new IntentFilter(LocationManager.MODE_CHANGED_ACTION);
        context.getApplicationContext().registerReceiver(this, intentFilter);
    }

    @Override
    public void onReceive(Context context, Intent intent)
    {
        Log.d(TAG, "onReceive:" + intent.getAction());
        if (intent.getAction() == WifiManager.NETWORK_STATE_CHANGED_ACTION) {
            NetworkInfo netInfo = intent.getParcelableExtra (WifiManager.EXTRA_NETWORK_INFO);
            if (ConnectivityManager.TYPE_WIFI == netInfo.getType ()) {
                readSsid();
            }
        }

        if (intent.getAction() == LocationManager.MODE_CHANGED_ACTION) {
            checkStatus();
        }
    }

    private void readSsid()
    {
        WifiManager wifiManager = (WifiManager) m_context.getApplicationContext().getSystemService(Context.WIFI_SERVICE);
        WifiInfo info = wifiManager.getConnectionInfo();
        String ssid = info.getSSID();
        Log.d(TAG, ssid);
        // if ssid is UTF-8 it's double quoted, otherwise it's a hex digit sequence
        // this is really the only case we care about in practice, so we just ignore the other forms
        if (ssid.startsWith("\"") && ssid.endsWith("\"")) {
            ssid = ssid.substring(1, ssid.length() - 1);
        }
        setSsid(ssid);
    }

    private void checkStatus()
    {
        // TODO check permission

        LocationManager locMgr = (LocationManager) m_context.getApplicationContext().getSystemService(Context.LOCATION_SERVICE);
        if (Build.VERSION.SDK_INT >= 28) {
            if (!locMgr.isLocationEnabled()) {
                Log.d(TAG, "Location not enabled");
                setStatus(NOT_ENABLED);
                return;
            }
        } else {
            if (!locMgr.isProviderEnabled(LocationManager.NETWORK_PROVIDER) && !locMgr.isProviderEnabled(LocationManager.GPS_PROVIDER)) {
                Log.d(TAG, "Location not enabled (legacy)");
                setStatus(NOT_ENABLED);
                return;
            }
        }

        Log.d(TAG, "wifi monitoring assumed to be available");
        readSsid();
        setStatus(AVAILABLE);
    }

    private native void setSsid(String ssid);
    private native void setStatus(int statusCode);

    private Context m_context;
}
