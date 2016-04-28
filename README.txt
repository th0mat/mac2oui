
// mac2oui - mac address lookup
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//
// A tool to turn mac addresses into short strings showing
// either the name linked to known mac addresses or the manufacturer
// of the equipment as per the information encoded in the mac address.
//
// Examples for lookup results
// ---------------------------
//
// (1) Nema's_mobile   // known mac address
// (2) Apple_A2F3      // unknown mac with known manufacturer
//                     // 'A2F3' for the last two bytes of the specific address
// (3) [FFCDEE999999]  // unknown mac with unknown manufacturer
//
//
// Data sources
// ------------
//
// (1) known macs as defined in macs_known.txt in directory manufconfig
// (2) a table of all OUI - Organizationally Unique Identifiers as maintained by IEEE
//
// Data updates
// ------------
//
// Download latest version from
// https://code.wireshark.org/review/gitweb?p=wireshark.git;a=blob_plain;f=manuf;hb=HEAD
// as macs_all.txt in manufconfig directory.
//
// Lookup via
// ----------
//
// (1) hex string of mac address or
// (2) u_char pointer to a mac address in network byte order or
// (3) u_int64 representation of mac address
//
// Tool usage example
// ------------------
//
// #include "mac2oui"
// std::string result = resolveMac(yourMac);
