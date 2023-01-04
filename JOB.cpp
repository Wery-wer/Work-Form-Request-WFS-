#include "wrf.h"

void createListJob(listJob &LJ) { first(LJ) = NULL; }

adrJob newJOB(string jobID, string desc) {
  adrJob p;
  p = new job;
  info(p).jobID = jobID;
  info(p).desc = desc;
  nextJob(p) = NULL;

  return p;
}

void addJOB(listJob &LJ, adrJob p) {
  adrJob q = first(LJ);
  if (first(LJ) == NULL) {
    first(LJ) = p;
  } else {
    while (nextJob(q) != NULL) {
      q = nextJob(q);
    }
    nextJob(q) = p;
  }
}

void ShowAllJobRequest(listJob LJ) {
  adrJob q = first(LJ);
  if (first(LJ) == NULL) {
    cout << "List Job Kosong" << endl;
  } else {
    cout << left << setw(5) << "ID" << left << setw(25) << "Description"
         << endl;
    while (q != NULL) {
      cout << left << setw(5) << info(q).jobID << left << setw(25)
           << info(q).desc << endl;
      q = nextJob(q);
    }
  }
}

adrJob findJobByID(listJob LJ, string job_ID) {
  adrJob p = first(LJ);
  while (p != NULL) {
    if (info(p).jobID == job_ID) {
      return p;
    }
    p = nextJob(p);
  }
  return NULL;
}
