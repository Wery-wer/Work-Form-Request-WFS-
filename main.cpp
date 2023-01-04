#include "wrf.h"

int main() {
  listNoc LN;
  createListNoc(LN);
  infoNOC inoc;
  adrNOC q;

  listJob LJ;
  createListJob(LJ);
  infoJob ijob;
  adrJob r;

  listRel LR;
  createListWRF(LR);
  infoRelation irel;
  string noc_ID, job_id, noc_status;
  string stat;
  adrRel p;

  int x, i;
  int pilihan = selectMenu();
  while (pilihan != 0) {
    cout << endl;
    switch (pilihan) {
    case 1:
      cout << "Jumlah NOC yang ditambahkan: ";
      cin >> x;
      cout << endl;
      i = 0;
      while (i < x) {
        cout << "Masukkan data baru: " << endl;
        cout << "NOC ID: ";
        cin >> inoc.nocID;
        cout << "NOC NAME: ";
        cin >> inoc.nocName;
        cout << "NOC AREA: ";
        cin >> inoc.area;

        addNoc(LN, newNOC(inoc.nocID, inoc.nocName, inoc.area));

        i++;
      }
      cout << endl;
      break;

    case 2:
      cout << "Jumlah Job Request yang ditambahkan: ";
      cin >> x;
      i = 0;
      while (i < x) {
        cout << "JOB ID: ";
        cin >> ijob.jobID;
        cout << "DESCRIPTION: ";
        cin >> ijob.desc;

        addJOB(LJ, newJOB(ijob.jobID, ijob.desc));
        i++;
      }
      cout << endl;
      break;

    case 3:
      cout << "Jumlah WRF yang akan ditambahkan: ";
      cin >> x;
      i = 0;
      while (i < x) {
        cout << "Masukkan NOC ID: ";
        cin >> noc_ID;
        cout << "Masukkan JOb ID: ";
        cin >> job_id;
        cout << "Masukkan Status: ";
        cin >> irel.status;
        cout << "Masukkan Item Remark: ";
        cin >> irel.item;
        cout << "Masukkan Customer: ";
        cin >> irel.customer;
        cout << endl;

        p = newRel(irel.status, irel.item, irel.customer);
        addWRF(LN, LJ, noc_ID, job_id, LR, p);
        i++;
      }
      cout << endl;
      break;

    case 4:
      cout << "List NOC Sebagai Berikut:" << endl;
      showAllNOC(LN);
      cout << endl;
      break;

    case 5:
      cout << "List Job Request Sebagai Berikut:" << endl;
      ShowAllJobRequest(LJ);
      cout << endl;
      break;

    case 6:
      cout << "List WRF Sebagai Berikut:" << endl;
      showAllWRF(LR);
      cout << endl;
      break;

    case 7:
      cout << "Masukkan NOC ID: ";
      cin >> noc_ID;

      cout << "Berikut List WRF berdasarkan NOC ID: " << noc_ID << endl;
      shoWRFNOC(LR, noc_ID);
      break;

    case 8:
      cout << "Masukkan Status: ";
      cin >> noc_status;

      cout << "Berikut List NOC berdasarkan status : " << noc_status << endl;
      ShowNOCbyStatus(LR, noc_status);
      break;

    case 9:
      ShowStat(LJ, LR);
      break;
    }
    pilihan = selectMenu();
  }
  cout << "Anda telah keluar"<<endl;
}
