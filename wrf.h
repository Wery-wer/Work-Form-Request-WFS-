#ifndef WRF_H_INCLUDED
#define WRF_H_INCLUDED

#include <iomanip>
#include <iostream>
using namespace std;

#define nextNoc(P) (P)->nextNoc
#define nextJob(P) (P)->nextJob
#define nextRel(P) (P)->nextRel
#define info(P) (P)->info
#define fnoc(P) (P)->info.fnoc
#define fjob(P) (P)->info.fjob
#define first(L) ((L).first)

// NODE NOC
struct infoNOC {
  string nocID;
  string nocName;
  string area;
};

typedef struct noc *adrNOC;
struct noc {
  infoNOC info;
  adrNOC nextNoc;
};

struct listNoc {
  adrNOC first;
};

// NODE JOB
typedef struct job *adrJob;
struct infoJob {
  string jobID;
  string desc;
};

typedef struct job *adrJob;
struct job {
  infoJob info;
  adrJob nextJob;
};

struct listJob {
  adrJob first;
};

// NODE RELATION
struct infoRelation {
  adrNOC fnoc;
  adrJob fjob;
  string status;
  string item;
  string customer;
};

typedef struct Rel *adrRel;
struct Rel {
  infoRelation info;
  adrRel nextRel;
};

struct listRel {
  adrRel first;
};

// NODE NOC
void createListNoc(listNoc &LN);
adrNOC newNOC(string nocID, string nocName, string area);
void addNoc(listNoc &LN, adrNOC p);
void showAllNOC(listNoc LN);
void ShowNOCbyStatus(listRel &LR, string status);
adrNOC findNOCbyID(listNoc LN, string noc_ID);

// NODE JOB
void createListJob(listJob &LJ);
adrJob newJOB(string jobID, string desc);
void addJOB(listJob &LJ, adrJob p);
void ShowAllJobRequest(listJob LJ);
adrJob findJobByID(listJob LJ, string job_ID);

// NODE WRF
void createListWRF(listRel &LR);
adrRel newRel(string status, string item, string customer);
void addWRF(listNoc LN, listJob LJ, string noc_ID, string job_ID, listRel &LR,
            adrRel p);
void shoWRFNOC(listRel &LR, string nocID);
void showAllWRF(listRel LR);
void ShowStat(listJob LJ, listRel LR);

// MENU
int selectMenu();

#endif // WRF_H_INCLUDED
