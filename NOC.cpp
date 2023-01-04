#include "wrf.h"

void createListNoc(listNoc &LN) { first(LN) = NULL; }

adrNOC newNOC(string nocID, string nocName, string area) {
  adrNOC p;
  p = new noc;
  info(p).nocID = nocID;
  info(p).nocName = nocName;
  info(p).area = area;
  nextNoc(p) = NULL;

  return p;
}

void addNoc(listNoc &LN, adrNOC p) {
  adrNOC q = first(LN);
  if (first(LN) == NULL) {
    first(LN) = p;
  } else {
    while (nextNoc(q) != NULL) {
      q = nextNoc(q);
    }
    nextNoc(q) = p;
  }
}

void showAllNOC(listNoc LN) {
  adrNOC P = first(LN);
  if (first(LN) == NULL) {
    cout << "List Kosong";
  } else {
    cout << left << setw(5) << "ID" << left << setw(15) << "NOC_NAME"
         << setw(10) << "AREA" << endl;
    while (P != NULL) {
      cout << left << setw(5) << info(P).nocID << left << setw(15)
           << info(P).nocName << setw(10) << info(P).area << endl;
      P = nextNoc(P);
    }
  }
}

adrNOC findNOCbyID(listNoc LN, string noc_ID) {
  adrNOC p = first(LN);
  while (p != NULL) {
    if (info(p).nocID == noc_ID) {
      return p;
    }
    p = nextNoc(p);
  }
  return NULL;
}
