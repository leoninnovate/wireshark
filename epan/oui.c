/* oui.c
 * Routines and tables for processing OUIs
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 - 2000 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "config.h"

#include <epan/value_string.h>
#include <epan/oui.h>

/*
 * See
 *
 * http://standards.ieee.org/regauth/oui/oui.txt
 *
 * http://www.cisco.com/univercd/cc/td/doc/product/lan/trsrb/vlan.htm
 *
 * for the PIDs for VTP and DRiP that go with an OUI of OUI_CISCO.
 */
const value_string oui_vals[] = {
	{ OUI_ENCAP_ETHER,	"Encapsulated Ethernet" },
	{ OUI_XEROX,		"Xerox" },
/*
http://www.cisco.com/univercd/cc/td/doc/product/software/ios113ed/113ed_cr/ibm_r/brprt1/brsrb.htm
*/
	{ OUI_CISCO,			"Cisco" },
	{ OUI_NORTEL,			"Nortel Discovery Protocol" },
	{ OUI_CISCO_90,			"Cisco IOS 9.0 Compatible" },
	{ OUI_FORCE10,			"Force10 Networks" },
	{ OUI_ERICSSON,			"Ericsson Group" },
	{ OUI_CATENA,			"Catena Networks" },
	{ OUI_SONY_ERICSSON,	"Sony Ericsson Mobile Communications AB" },
	{ OUI_SONY_ERICSSON_2,	"Sony Ericsson Mobile Communications AB" },
	{ OUI_PROFINET,			"PROFIBUS Nutzerorganisation e.V." },
	{ OUI_SONY_ERICSSON_3,	"Sony Ericsson Mobile Communications AB" },
	{ OUI_CIMETRICS,		"Cimetrics" },
	{ OUI_IEEE_802_3,		"IEEE 802.3" },
	{ OUI_MEDIA_ENDPOINT,	"Media (TIA TR-41 Committee)" },
	{ OUI_SONY_ERICSSON_4,	"Sony Ericsson Mobile Communications AB" },
	{ OUI_ERICSSON_MOBILE,	"Ericsson Mobile Platforms" },
	{ OUI_SONY_ERICSSON_5,	"Sony Ericsson Mobile Communications AB" },
	{ OUI_SONY_ERICSSON_6,	"Sony Ericsson Mobile Communications AB" },
	{ OUI_SONY_ERICSSON_7,	"Sony Ericsson Mobile Communications AB" },
	{ OUI_BLUETOOTH,		"Bluetooth SIG, Inc." },
	{ OUI_SONY_ERICSSON_8,	"Sony Ericsson Mobile Communications AB" },
	{ OUI_IEEE_802_1QBG,	"IEEE 802.1Qbg" },
	{ OUI_TURBOCELL,		"Karlnet (Turbocell)" },
	{ OUI_CISCOWL,			"Cisco Wireless (Aironet) L2" },
	{ OUI_MARVELL,			"Marvell Semiconductor" },
	{ OUI_BRIDGED,			"Frame Relay or ATM bridged frames" },
	{ OUI_IEEE_802_1,		"IEEE 802.1 Committee" },
	{ OUI_ATM_FORUM,		"ATM Forum" },
	{ OUI_EXTREME,			"Extreme Networks" },
	/* RFC 2427, RFC 2684 */
	{ OUI_CABLE_BPDU,		"DOCSIS Spanning Tree" }, /* DOCSIS spanning tree BPDU */
	{ OUI_SIEMENS,			"Siemens AG" },
	{ OUI_APPLE_ATALK,		"Apple (AppleTalk)" },
	{ OUI_HP,				"Hewlett-Packard" },
	{ OUI_HP_2,				"Hewlett-Packard" },
	/* Registry Name: PPP Vendor Specific OUI Options */
	{ OUI_3GPP2,			"3GPP2 Vendor specific packet ID" },
	{ OUI_ERICSSON_2,		"Ericsson Group" },
	{ 0,	NULL }
};

const value_string tlv_oui_subtype_vals[] = {
    /* Currently, the manuf file calls this "Ieee8021"; "IEEE 802.1" looks better */
    { OUI_IEEE_802_1,       "IEEE 802.1" },
    /* Currently, the manuf file calls this "Ieee8023"; "IEEE 802.3" looks better */
    { OUI_IEEE_802_3,       "IEEE 802.3" },
    /* Currently, the manuf file calls this "Telecomm"; "TIA TR-41 Committee" looks better */
    { OUI_MEDIA_ENDPOINT,   "TIA TR-41 Committee" },
    /* Currently, the manuf file calls this "Profibus" */
    { OUI_PROFINET,         "PROFINET" },
    /* Currently, the manuf file calls this "Procurve", as it's assigned to HP! */
    { OUI_IEEE_802_1QBG,    "IEEE 802.1Qbg" },
    /*  Data Center Bridging Exchange */
    { OUI_DCBX,             "Data Center Bridging Capabilities Exchange" },
    { 0, NULL }
};

