#!/usr/bin/env python3

# SPDX-FileCopyrightText: 2024 Jonah Brüchert <jbb@kaidan.im>
#
# SPDX-License-Identifier: LGPL-2.0-or-later

import sys
from bs4 import BeautifulSoup
import subprocess

table_path = sys.argv[1]
cpp_path   = sys.argv[2]

table = open(table_path, "r")
soup = BeautifulSoup(table, 'html.parser')

rows = soup.find_all("tr")

map = {}

for row in rows:
	data = row.find_all("td")
	if len(data) == 8:
		map[data[0].get_text().strip()] = data[2].get_text().strip()
		map[data[1].get_text().strip()] = data[3].get_text().strip()

	if len(data) == 4:
	        map[data[0].get_text().strip()] = data[1].get_text().strip()


out = open(cpp_path, "w")
out.write("{\n")
for row in map.items():
	k = row[0]
	v = row[1]
	out.write(f"    {{u'{k}', u\"{v}\"}},\n")

out.write("}")
out.close()
