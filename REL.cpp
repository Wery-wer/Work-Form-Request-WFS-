#include "wrf.h"

void createListWRF(listRel &LR) { first(LR) = NULL; }

adrRel newRel(string status, string item, string customer) {
  adrRel p;
  p = new Rel;
  info(p).status = status;
  info(p).item = item;
  info(p).customer = customer;
  fnoc(p) = NULL;
  fjob(p) = NULL;
  nextRel(p) = NULL;

  return p;
}

void addWRF(listNoc LN, listJob LJ, string noc_ID, string job_ID, listRel &LR,
            adrRel p) {
  adrNOC q = NULL;
  adrJob r = NULL;
  q = findNOCbyID(LN, noc_ID);
  r = findJobByID(LJ, job_ID);
  adrRel s = first(LR);
  if (q != NULL && r != NULL) {
    p->info.fnoc = q;
    p->info.fjob = r;
    if (first(LR) == NULL) {
      first(LR) = p;
    } else {
      while (nextRel(s) != NULL) {
        s = nextRel(s);
      }
      nextRel(s) = p;
    }
  } else {
    cout << "NOC/JOB tidak tersedia!!" << endl;
  }
}

void shoWRFNOC(listRel &LR, string nocID) {
  adrRel p = first(LR);
  int jumlah = 0;
  if (first(LR) != NULL) {
    cout << left << setw(7) << "nocID" << left << setw(7) << "jobID" << left
         << setw(10) << "STATUS" << left << setw(15) << "ITEM REMARK" << left
         << setw(15) << "CUSTOMER" << endl;
    while (p != NULL) {
      if (fnoc(p)->info.nocID == nocID) {
        cout << left << setw(7) << fnoc(p)->info.nocID << left << setw(7)
             << fjob(p)->info.jobID << left << setw(10) << info(p).status
             << left << setw(15) << info(p).item << left << setw(15)
             << info(p).customer << endl;
        jumlah++;
      }
      p = nextRel(p);
    }
    cout << endl;
    cout << "Total WRF: " << jumlah << endl;
    cout << endl;
  } else {
    cout << "List WRF Kosong!!" << endl;
  }
}

void showAllWRF(listRel LR) {
  adrRel p = first(LR);
  int jum_open = 0, jum_closed = 0, jum_wait = 0;
  if (first(LR) != NULL) {
    cout << left << setw(7) << "nocID" << left << setw(7) << "jobID" << left
         << setw(10) << "STATUS" << left << setw(15) << "ITEM REMARK" << left
         << setw(15) << "CUSTOMER" << endl;
    while (p != NULL) {
      cout << left << setw(7) << fnoc(p)->info.nocID << left << setw(7)
           << fjob(p)->info.jobID << left << setw(10) << info(p).status << left
           << setw(15) << info(p).item << left << setw(15) << info(p).customer
           << endl;
      p = nextRel(p);
    }
  } else {
    cout << "List WRF Kosong!!" << endl;
  }
}

void ShowNOCbyStatus(listRel &LR, string status) {
  adrRel p = first(LR);
  adrNOC q;
  if (first(LR) != NULL) {
    cout << left << setw(5) << "ID" << left << setw(15) << "NOC_NAME"
         << setw(10) << "AREA" << endl;
    while (p != NULL) {
      if (info(p).status == status) {
        q = fnoc(p);
        cout << left << setw(5) << info(q).nocID << left << setw(15)
             << info(q).nocName << setw(10) << info(q).area << endl;
      }
      p = nextRel(p);
    }
  } else {
    cout << "List WRF Kosong!!" << endl;
  }
}

void ShowStat(listJob LJ, listRel LR) {
  adrRel p;
  adrJob q = first(LJ);
  int temp;
  int jum_open, jum_wait, jum_closed;
  cout << "+=======+=========================+=============+==========+========"
          "==+==========+\n";
  cout << "|" << left << setw(7) << "JOB ID"
       << "|" << left << setw(25) << "Job Description"
       << "|" << left << setw(13) << "JUMLAH NOC"
       << "|   " << left << setw(7) << "OPEN"
       << "| " << left << setw(9) << "WAITING"
       << "|  " << left << setw(8) << "CLOSED"
       << "|" << endl;
  cout << "+=======+=========================+=============+==========+========"
          "==+==========+\n";
  int open = 0;
  int waiting = 0;
  int closed = 0;
  //===================================================================
  while (q != NULL) {
    temp = 0;
    jum_closed = 0, jum_open = 0, jum_wait = 0;

    p = first(LR);
    while (p != NULL) {
      if (info(q).jobID == fjob(p)->info.jobID) {
        temp++;
        if (info(p).status == "OPEN") {
          jum_open++;
        } else if (info(p).status == "WAITING") {
          jum_wait++;
        } else {
          jum_closed++;
        }
      }
      p = nextRel(p);
    }
    open = jum_open + open;
    waiting = jum_wait + waiting;
    closed = jum_closed + closed;
    cout << "|  " << left << setw(5) << info(q).jobID << "|" << left << setw(25)
         << info(q).desc << "|      " << left << setw(7) << temp << "|    "
         << left << setw(6) << jum_open << "|     " << left << setw(5)
         << jum_wait << "|     " << left << setw(5) << jum_closed << "|"
         << endl;
    q = nextJob(q);
  }
  cout << "+=======+=========================+=============+==========+========"
          "==+==========+\n";
  cout << endl;
  cout << "Jumlah Status Open\t: " << open << endl;
  cout << "Jumlah Status Waiting\t: " << waiting << endl;
  cout << "Jumlah Status Closed\t: " << closed << endl;
  cout << endl;
}
int selectMenu() {
  cout << "==========================MENU==========================" << endl;
  cout << "1. Menambah N data NOC" << endl;
  cout << "2. Menambah N data Job Request" << endl;
  cout << "3. Menambah WRF" << endl;
  cout << "4. Menampilkan seluruh data NOC" << endl;
  cout << "5. Menampilkan seluruh data Job Request" << endl;
  cout << "6. Menampilkan seluruh WRF" << endl;
  cout << "7. Menampilkan WRF berdasarkan nocID" << endl;
  cout << "8. Menampilkan seluruh NOC berdasarkan status" << endl;
  cout << "9. Menampilkan Status" << endl;
  cout << "0. Keluar Program" << endl;

  cout << "Pilihan Menu: ";

  int input = 0;
  cin >> input;
  return input;
}
