/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "osmelementinformationmodel.h"
#include "osmelementinformationmodel_p.h"

namespace KOSMIndoorMap {

// TODO expand this, see:
// - https://taginfo.openstreetmap.org/keys/?key=amenity#values
// - https://taginfo.openstreetmap.org/keys/?key=shop#values
// - https://taginfo.openstreetmap.org/keys/?key=tourism#values
// - parts of https://taginfo.openstreetmap.org/keys/?key=office#values
// - parts of https://taginfo.openstreetmap.org/keys/?key=room#values
static constexpr const ValueMapEntry amenity_map[] = {
    { "alcohol", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Alcohol") },
    { "atm", QT_TRANSLATE_NOOP("OSM::amenity/shop", "ATM") },
    { "attraction", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Attraction") },
    { "bag", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Bag") },
    { "bakery", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Bakery") },
    { "bank", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Bank") },
    { "bar", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Bar") },
    { "beauty", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Beauty") },
    { "bed", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Bed") },
    { "beverages", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Beverages") },
    { "bicycle", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Bicycle") },
    { "bicycle_parking", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Bicycle Parking") },
    { "bicycle_rental", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Bicycle Rental") },
    { "books", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Books") },
    { "boutique", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Boutique") },
    { "bureau_de_change", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Bureau de Change") },
    { "butcher", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Butcher") },
    { "cafe", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Cafe") },
    { "car", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Car") },
    { "car_rental", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Car Rental") },
    { "car_sharing", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Car Sharing") },
    { "charging_station", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Charging Station") },
    { "chemist", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Chemist") },
    { "chocolate", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Chocolate") },
    { "cinema", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Cinema") },
    { "clothes", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Clothes") },
    { "coffee", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Coffee") },
    { "computer", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Computer") },
    { "confectionery", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Confectionery") },
    { "convenience", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Convenience Store") },
    { "copyshop", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Copy Shop") },
    { "cosmetics", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Cosmetics") },
    { "courthouse", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Court House") },
    { "deli", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Deli") },
    { "department_store", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Department Store") },
    { "doctors", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Doctor") },
    { "doityourself", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Hardware Store") },
    { "dry_cleaning", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Dry Cleaning") },
    { "electronics", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Electronics") },
    { "fashion", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Fashion") },
    { "fast_food", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Fast Food") },
    { "florist", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Florist") },
    { "food_court", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Food Court") },
    { "fountain", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Fountain") },
    { "furniture", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Furniture") },
    { "garden_centre", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Garden Center") },
    { "gift", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Gift Shop") },
    { "greengrocer", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Greengrocer") },
    { "guest_house", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Guest House") },
    { "hairdresser", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Hairdresser") },
    { "hearing_aids", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Hearing Aids") },
    { "hospital", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Hospital") },
    { "hostel", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Hostel") },
    { "hotel", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Hotel") },
    { "houseware", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Houseware") },
    { "ice_cream", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Ice Cream") },
    { "information", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Information") },
    { "interior_decoration", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Interior Decoration") },
    { "internet_cafe", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Internet Cafe") },
    { "jewelry", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Jewelry") },
    { "kiosk", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Kiosk") },
    { "laundry", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Laundry") },
    { "library", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Library") },
    { "lockers", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Locker") },
    { "locksmith", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Locksmith") },
    { "lost_and_found", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Lost & Found") },
    { "lost_property", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Lost & Found") },
    { "luggage_locker", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Locker") },
    { "mall", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Mall") },
    { "medical_supply", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Medical Supply") },
    { "mobile_phone", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Mobile Phone") },
    { "money_transfer", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Money Transfer") },
    { "motorcycle_parking", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Motorcycle Parking") },
    { "museum", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Museum") },
    { "music", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Music") },
    { "musical_instrument", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Musical Instruments") },
    { "newsagent", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Newsagent") },
    { "office", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Office") },
    { "optician", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Optician") },
    { "outdoor", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Outdoor") },
    { "paint", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Paint") },
    { "parking", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Parking") },
    { "parking_tickets", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Parking Tickets") },
    { "pastry", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Pastry") },
    { "perfumery", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Perfumery") },
    { "pet", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Pet") },
    { "pharmacy", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Pharmacy") },
    { "photo", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Photo") },
    { "place_of_worship", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Place of Worship") },
    { "police", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Police") },
    { "post_box", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Post Box") },
    { "post_office", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Post Office") },
    { "pub", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Pub") },
    { "public_transport_tickets", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Public Transport Tickets") },
    { "recycling", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Recycling") },
    { "restaurant", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Restaurant") },
    { "school", QT_TRANSLATE_NOOP("OSM::amenity/shop", "School") },
    { "seafood", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Seafood") },
    { "shoes", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Shoes") },
    { "shop", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Shop") },
    { "social_facility", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Social Facility") },
    { "souveniers", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Souveniers") },
    { "sports", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Sports") },
    { "stationery", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Stationery") },
    { "supermarket", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Supermarket") },
    { "tailor", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Tailor") },
    { "tatoo", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Tattoo") },
    { "taxi", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Taxi") },
    { "tea", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Tea") },
    { "theatre", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Theatre") },
    { "ticket", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Tickets") },
    { "tobacco", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Tobacco") },
    { "toilets", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Toilets") },
    { "toys", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Toys") },
    { "travel_agency", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Travel Agency") },
    { "travel_agent", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Travel Agency") },
    { "university", QT_TRANSLATE_NOOP("OSM::amenity/shop", "University") },
    { "variety_store", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Variety Store") },
    { "video_games", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Video Games") },
    { "waiting", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Waiting Area") },
    { "waiting_area", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Waiting Area") },
    { "waiting_room", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Waiting Area") },
    { "wine", QT_TRANSLATE_NOOP("OSM::amenity/shop", "Wine") },
};
static_assert(isSortedLookupTable(amenity_map), "amenity map is not sorted!");

// TODO expand this, see https://taginfo.openstreetmap.org/keys/cuisine#values
static constexpr const ValueMapEntry cuisine_map[] = {
    { "american", QT_TRANSLATE_NOOP("OSM::cuisine", "American") },
    { "arab", QT_TRANSLATE_NOOP("OSM::cuisine", "Arab") },
    { "argentinian", QT_TRANSLATE_NOOP("OSM::cuisine", "Argentinian") },
    { "asian", QT_TRANSLATE_NOOP("OSM::cuisine", "Asian") },
    { "austrian", QT_TRANSLATE_NOOP("OSM::cuisine", "Austrian") },
    { "barbecue", QT_TRANSLATE_NOOP("OSM::cuisine", "BBQ") },
    { "bbq", QT_TRANSLATE_NOOP("OSM::cuisine", "BBQ") },
    { "brazilian", QT_TRANSLATE_NOOP("OSM::cuisine", "Brazilian") },
    { "breakfast", QT_TRANSLATE_NOOP("OSM::cuisine", "Breakfast") },
    { "burger", QT_TRANSLATE_NOOP("OSM::cuisine", "Burger") },
    { "cake", QT_TRANSLATE_NOOP("OSM::cuisine", "Cake") },
    { "chicken", QT_TRANSLATE_NOOP("OSM::cuisine", "Chicken") },
    { "chinese", QT_TRANSLATE_NOOP("OSM::cuisine", "Chinese") },
    { "coffee_shop", QT_TRANSLATE_NOOP("OSM::cuisine", "Coffee Shop") },
    { "cookies", QT_TRANSLATE_NOOP("OSM::cuisine", "Cookies") },
    { "crepe", QT_TRANSLATE_NOOP("OSM::cuisine", "Crêpe") },
    { "donut", QT_TRANSLATE_NOOP("OSM::cuisine", "Donut") },
    { "falafel", QT_TRANSLATE_NOOP("OSM::cuisine", "Falafel") },
    { "fish", QT_TRANSLATE_NOOP("OSM::cuisine", "Fish") },
    { "fish_and_chips", QT_TRANSLATE_NOOP("OSM::cuisine", "Fish & Chips") },
    { "french", QT_TRANSLATE_NOOP("OSM::cuisine", "French") },
    { "german", QT_TRANSLATE_NOOP("OSM::cuisine", "German") },
    { "greek", QT_TRANSLATE_NOOP("OSM::cuisine", "Greek") },
    { "ice_cream", QT_TRANSLATE_NOOP("OSM::cuisine", "Ice Cream") },
    { "indian", QT_TRANSLATE_NOOP("OSM::cuisine", "Indian") },
    { "indonesian", QT_TRANSLATE_NOOP("OSM::cuisine", "Indonesian") },
    { "international", QT_TRANSLATE_NOOP("OSM::cuisine", "International") },
    { "italian", QT_TRANSLATE_NOOP("OSM::cuisine", "Italian") },
    { "italian_pizza", QT_TRANSLATE_NOOP("OSM::cuisine", "Pizza") },
    { "japanese", QT_TRANSLATE_NOOP("OSM::cuisine", "Japanese") },
    { "juice", QT_TRANSLATE_NOOP("OSM::cuisine", "Juice") },
    { "kebab", QT_TRANSLATE_NOOP("OSM::cuisine", "Kebab") },
    { "korean", QT_TRANSLATE_NOOP("OSM::cuisine", "Korean") },
    { "lebanese", QT_TRANSLATE_NOOP("OSM::cuisine", "Lebanese") },
    { "local", QT_TRANSLATE_NOOP("OSM::cuisine", "Local") },
    { "mediterranean", QT_TRANSLATE_NOOP("OSM::cuisine", "Mediterranean") },
    { "mexican", QT_TRANSLATE_NOOP("OSM::cuisine", "Mexican") },
    { "noodle", QT_TRANSLATE_NOOP("OSM::cuisine", "Noodle") },
    { "pakistani", QT_TRANSLATE_NOOP("OSM::cuisine", "Pakistani") },
    { "pancake", QT_TRANSLATE_NOOP("OSM::cuisine", "Pancake") },
    { "pasta", QT_TRANSLATE_NOOP("OSM::cuisine", "Pasta") },
    { "pizza", QT_TRANSLATE_NOOP("OSM::cuisine", "Pizza") },
    { "polish", QT_TRANSLATE_NOOP("OSM::cuisine", "Polish") },
    { "portuguese", QT_TRANSLATE_NOOP("OSM::cuisine", "Portuguese") },
    { "ramen", QT_TRANSLATE_NOOP("OSM::cuisine", "Ramen") },
    { "regional", QT_TRANSLATE_NOOP("OSM::cuisine", "Regional") },
    { "salad", QT_TRANSLATE_NOOP("OSM::cuisine", "Salad") },
    { "sandwich", QT_TRANSLATE_NOOP("OSM::cuisine", "Sandwich") },
    { "sausage", QT_TRANSLATE_NOOP("OSM::cuisine", "Sausage") },
    { "seafood", QT_TRANSLATE_NOOP("OSM::cuisine", "Seafood") },
    { "soup", QT_TRANSLATE_NOOP("OSM::cuisine", "Soup") },
    { "spanish", QT_TRANSLATE_NOOP("OSM::cuisine", "Spanish") },
    { "steak", QT_TRANSLATE_NOOP("OSM::cuisine", "Steak") },
    { "steak_house", QT_TRANSLATE_NOOP("OSM::cuisine", "Steak") },
    { "sushi", QT_TRANSLATE_NOOP("OSM::cuisine", "Sushi") },
    { "tapas", QT_TRANSLATE_NOOP("OSM::cuisine", "Tapas") },
    { "thai", QT_TRANSLATE_NOOP("OSM::cuisine", "Thai") },
    { "turkish", QT_TRANSLATE_NOOP("OSM::cuisine", "Turkish") },
    { "vegetarian", QT_TRANSLATE_NOOP("OSM::cuisine", "Vegetarian") },
    { "vietnamese", QT_TRANSLATE_NOOP("OSM::cuisine", "Vietnamese") },
};
static_assert(isSortedLookupTable(cuisine_map), "cuising map is not sorted!");

// diet types offered at restaurants
struct {
    const char *keyName;
    const char *label;

    constexpr inline OSMElementInformationModel::Key key() const { return OSMElementInformationModel::Diet; }
    constexpr inline OSMElementInformationModel::KeyCategory category() const { return OSMElementInformationModel::Main; }
} static constexpr const diet_type_map[] = {
    { "diet:gluten_free", QT_TRANSLATE_NOOP("OSM::diet_type", "gluten free") },
    { "diet:halal", QT_TRANSLATE_NOOP("OSM::diet_type", "halal") },
    { "diet:kosher", QT_TRANSLATE_NOOP("OSM::diet_type", "kosher") },
    { "diet:lactose_free", QT_TRANSLATE_NOOP("OSM::diet_type", "lactose free") },
    { "diet:vegan", QT_TRANSLATE_NOOP("OSM::diet_type", "vegan") },
    { "diet:vegetarian", QT_TRANSLATE_NOOP("OSM::diet_type", "vegetarian") },
};
static_assert(isSortedLookupTable(diet_type_map), "diet type map is not sorted!");

// generic payment types (excluding cash, that's handled separately)
struct {
    const char *keyName;
    OSMElementInformationModel::Key m_key;

    constexpr inline OSMElementInformationModel::Key key() const { return m_key; }
    constexpr inline OSMElementInformationModel::KeyCategory category() const { return OSMElementInformationModel::Payment; }
} static constexpr const payment_generic_type_map[] = {
    { "payment:account_cards", OSMElementInformationModel::PaymentDebitCard },
    { "payment:credit_cards", OSMElementInformationModel::PaymentCreditCard },
    { "payment:debit_cards", OSMElementInformationModel::PaymentDebitCard },
    { "payment:electronic_purses", OSMElementInformationModel::PaymentStoredValueCard },
};
static_assert(isSortedLookupTable(payment_generic_type_map), "generic payment type map is not sorted!");

// payment vendor types only, generic ones go into the list above and are handled separately
struct {
    const char *keyName;
    OSMElementInformationModel::Key m_key;
    const char *label;

    constexpr inline OSMElementInformationModel::Key key() const { return m_key; }
    constexpr inline OSMElementInformationModel::KeyCategory category() const { return OSMElementInformationModel::Payment; }
} static constexpr const payment_type_map[] = {
    { "payment:american_express", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("OSM::payment_method", "American Express") },
    { "payment:apple_pay", OSMElementInformationModel::PaymentDigital, QT_TRANSLATE_NOOP("OSM::payment_method", "Apple Pay") },
    { "payment:diners_club", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("OSM::payment_method", "Diners Club") },
    { "payment:discover_card", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("OSM::payment_method", "Discover Card") },
    { "payment:jcb", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("OSM::payment_method", "JCB") },
    { "payment:girocard", OSMElementInformationModel::PaymentDebitCard, QT_TRANSLATE_NOOP("OSM::payment_method", "Girocard") },
    { "payment:google_pay", OSMElementInformationModel::PaymentDigital, QT_TRANSLATE_NOOP("OSM::payment_method", "Google Pay") },
    { "payment:maestro", OSMElementInformationModel::PaymentDebitCard, QT_TRANSLATE_NOOP("OSM::payment_method", "Maestro") },
    { "payment:mastercard", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("OSM::payment_method", "Mastercard") },
    { "payment:unionpay", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("OSM::payment_method", "UnionPay") },
    { "payment:v_pay", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("OSM::payment_method", "V Pay") },
    { "payment:vpay", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("OSM::payment_method", "V Pay") },
    { "payment:visa", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("OSM::payment_method", "Visa") },
};

static constexpr const ValueMapEntry wheelchair_map[] = {
    { "limited", QT_TRANSLATE_NOOP("OSM::wheelchair_access", "limited") },
    { "no", QT_TRANSLATE_NOOP("OSM::wheelchair_access", "no") },
    { "yes", QT_TRANSLATE_NOOP("OSM::wheelchair_access", "yes") },
};
static_assert(isSortedLookupTable(wheelchair_map), "wheelchair access map is not sorted!");

// socket types for charging stations
struct {
    const char *keyName;
    const char *label;

    constexpr inline OSMElementInformationModel::Key key() const { return OSMElementInformationModel::Socket; }
    constexpr inline OSMElementInformationModel::KeyCategory category() const { return OSMElementInformationModel::Main; }
} static constexpr const socket_type_map[] = {
    { "socket:chademo", QT_TRANSLATE_NOOP("OSM::charging_station_socket", "Chademo") },
    { "socket:schuko", QT_TRANSLATE_NOOP("OSM::charging_station_socket", "Schuko") },
    { "socket:tesla_standard", QT_TRANSLATE_NOOP("OSM::charging_station_socket", "Tesla") },
    { "socket:tesla_supercharger", QT_TRANSLATE_NOOP("OSM::charging_station_socket", "Tesla Supercharger") },
    { "socket:tesla_supercharger_ccs", QT_TRANSLATE_NOOP("OSM::charging_station_socket", "Tesla Supercharger CCS") },
    { "socket:type2", QT_TRANSLATE_NOOP("OSM::charging_station_socket", "Type 2") },
    { "socket:type2_cable", QT_TRANSLATE_NOOP("OSM::charging_station_socket", "Type 2 cable") },
    { "socket:type2_combo", QT_TRANSLATE_NOOP("OSM::charging_station_socket", "Type 2 CCS") },
};
static_assert(isSortedLookupTable(socket_type_map), "socket type map is not sorted!");

// charging station authentication methods
struct {
    const char *keyName;
    const char *label;

    constexpr inline OSMElementInformationModel::Key key() const { return OSMElementInformationModel::Authentication; }
    constexpr inline OSMElementInformationModel::KeyCategory category() const { return OSMElementInformationModel::Main; }
} static constexpr const authentication_type_map[] = {
    { "authentication:app", QT_TRANSLATE_NOOP("OSM::charging_station_authentication", "app") },
    { "authentication:membership_card", QT_TRANSLATE_NOOP("OSM::charging_station_authentication", "membership card") },
    { "authentication:nfc", QT_TRANSLATE_NOOP("OSM::charging_station_authentication", "NFC") },
    { "authentication:none", QT_TRANSLATE_NOOP("OSM::charging_station_authentication", "none") },
    { "authentication:phone_call", QT_TRANSLATE_NOOP("OSM::charging_station_authentication", "phone call") },
    { "authentication:short_message", QT_TRANSLATE_NOOP("OSM::charging_station_authentication", "SMS") },
};
static_assert(isSortedLookupTable(authentication_type_map), "authentication type map is not sorted!");

// bicycle parking values
// see https://taginfo.openstreetmap.org/keys/?key=bicycle_parking#values
static constexpr const ValueMapEntry bicycle_parking_map[] = {
    { "anchors", QT_TRANSLATE_NOOP("OSM::bicycle_parking", "anchors") },
    { "bollard", QT_TRANSLATE_NOOP("OSM::bicycle_parking", "bollard") },
    { "building", QT_TRANSLATE_NOOP("OSM::bicycle_parking", "building") },
    { "ground_slots", QT_TRANSLATE_NOOP("OSM::bicycle_parking", "ground slots") },
    { "lockers", QT_TRANSLATE_NOOP("OSM::bicycle_parking", "lockers") },
    { "racks", QT_TRANSLATE_NOOP("OSM::bicycle_parking", "racks") },
    { "shed", QT_TRANSLATE_NOOP("OSM::bicycle_parking", "shed") },
    { "stands", QT_TRANSLATE_NOOP("OSM::bicycle_parking", "stands") },
    { "wall_loops", QT_TRANSLATE_NOOP("OSM::bicycle_parking", "wall loops") },
    { "wide_stands", QT_TRANSLATE_NOOP("OSM::bicycle_parking", "wide stands") },
};
static_assert(isSortedLookupTable(bicycle_parking_map), "bicycle parking map is not sorted!");

}
