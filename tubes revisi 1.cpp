#include<iostream>
#include<fstream>
#include<cstdlib>
#include<math.h>
using namespace std;
int main(){
    int i,j,k,l,pilih,pilih1,pilih2,m,n;
    float a,b,c,d,det,r;
    cout<<"Pilih cara input nilai [1/2] :"<<endl;
    cout<<"1. File txt"<<endl;
    cout<<"2. Keyboard"<<endl;
    cout<<"Pilihan = ";
    cin>>pilih;
    cout<<endl;

    if(pilih==1){
    string baris;
    ifstream bukafile;
    bukafile.open("matriks.txt");

    cout << endl << "Bentuk Matriks " << endl;
    if (bukafile.is_open())
    {
        while ( getline (bukafile,baris) )
        {
            cout << baris <<'\n';
        }
        bukafile.close();
    }
    else{ cout << "File tidak ditemukan";}

    cout<<"MENU"<<endl;
    cout <<endl;
        cout<<"1. Sistem Persamaan Linear"<<endl;
        cout<<"2. Determinan"<<endl;
        cout<<"3. Matriks balikan"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Pilihan = ";
        cin>>pilih1;
        if(pilih1==1){
            cout<<endl;
            cout<<"1. Metode eliminasi Gauss"<<endl;
            cout<<"2. Metode eliminasi Gaus-Jordan"<<endl;
            cout<<"3. Metode matriks balikan"<<endl;
            cout<<"4. Kaidah Cramer"<<endl;
            cout<<"Pilihan = ";
            cin>>pilih2;

            if(pilih2==1){
                int n, m;
                float A;
                cout << "Masukkan banyak variabel : ";
                cin >> n;
                cout << "Masukkan banyak persamaan : ";
                cin >> m;
                float ruaskiri[m][n+1];
                float ruaskanan[m];
                for(int i=0; i<m; i++){
                    for(int j=0; j<=n;j++){
                        if(j==n){
            //				cout <<"B["<<i+1<<"] : ";
                            cin >> ruaskiri[i][j];
                        }else{
            //				cout << "A" << "["<<i+1<<"]["<<j+1<<"] : ";
                            cin >> ruaskiri[i][j];
                        }
                    }
                }
                for(int i=0; i<m; i++){
                    for(int j=0; j<=n;j++){
                        if(j==n){
                            cout<<" = "<<ruaskiri[i][j]<<endl;
                        }else{
                            cout << ruaskiri[i][j]<<"x"<<j+1<<"  ";
                        }
                    }
                    cout<<endl;
                }
            //	cout << "\n matriks augmented "<<endl;
            //	for(int i=0; i<m; i++){
            //		for(int j=0; j<n+1;j++){
            //			cout << ruaskiri[i][j]<<"  ";
            //		}
            //		cout <<endl;
            //	}
            //	cout <<"Proses OBE matriks augmented";
                for(int i=0; i<n-1; i++){
                    for(int j=i+1; j<n; j++){
                        A = ruaskiri[j][i] / ruaskiri[i][i];
                        for(int k=0; k<n+1;k++){
                            ruaskiri[j][k] = ruaskiri[j][k] - A*ruaskiri[i][k];
                        }
                    }
                }
                    cout <<"\n  \n";
            //	for(int k=0;k<n;k++){
            //		for(int l=0;l<n;l++){
            //			cout <<ruaskiri[k][l]<<"  ";
            //		}
            //		cout<< ruaskiri[k][n]<<"  ";
            //		cout <<"\n  \n";
            //	}
                for(int k=0; k<n; k++){
                    ruaskanan[k]=ruaskiri[k][n];
                }
                //penghitungan x
                float temp;
                float Z[10];

                temp = ruaskiri[m-1][n-1];
                Z[m-1]=ruaskanan[m-1]/temp;

                for (int i=(n-2);i>=0;i--){
                    temp=ruaskiri[i][i];
                    for(int j=i+1; j<n; j++){
                        ruaskanan[i] =ruaskanan[i] - (ruaskiri[i][j]*Z[j]);
                    }
                    Z[i]=ruaskanan[i]/temp;
                }
                cout <<"\n Setelaah pengurutan dan perhitungan \n";
                for(int i=0; i<(n); i++){
                    cout <<"X"<<i+1<<" = "<<Z[i] <<endl;
                }
            }
            else if(pilih2==2){
                int n, m;
                float A;
                cout << "Masukkan banyak variabel : ";
                cin >> n;
                cout << "Masukkan banyak persamaan : ";
                cin >> m;
                float ruaskiri[m][n+1];
                float ruaskanan[m];
                for(int i=0; i<m; i++){
                    for(int j=0; j<=n;j++){
                        if(j==n){
            //				cout <<"B["<<i+1<<"] : ";
                            cin >> ruaskiri[i][j];
                        }else{
            //				cout << "A" << "["<<i+1<<"]["<<j+1<<"] : ";
                            cin >> ruaskiri[i][j];
                        }
                    }
                }
                for(int i=0; i<m; i++){
                    for(int j=0; j<=n;j++){
                        if(j==n){
                            cout<<" = "<<ruaskiri[i][j]<<endl;
                        }else{
                            cout << ruaskiri[i][j]<<"X"<<j+1<<"  ";
                        }
                    }
                    cout<<endl;
                }
            //	cout << "\n matriks augmented "<<endl;
            //	for(int i=0; i<m; i++){
            //		for(int j=0; j<n+1;j++){
            //			cout << ruaskiri[i][j]<<"  ";
            //		}
            //		cout <<endl;
            //	}
                for(int k=0; k<n; k++){
                    ruaskanan[k]=ruaskiri[k][n];
                }
                //penyelesaian gausjordan
                float temp;
                for(int i=0; i<n; i++){
                    //cout <<"\nTahap "<<i+1<<endl;
                    temp=ruaskiri[i][i];
                    for(int j=0; j<n; j++){
                        ruaskiri[i][j]=ruaskiri[i][j]/temp;
                    }
                    ruaskanan[i]=ruaskanan[i]/temp;
                    for(int k=0;k<n;k++){
                        if(k!=i){
                            temp=ruaskiri[k][i];
                            for(int j=0;j<n;j++){
                                ruaskiri[k][j]= ruaskiri[k][j]-(temp * ruaskiri[i][j]);
                            }
                            ruaskanan[k]=ruaskanan[k]-(temp*ruaskanan[i]);
                        }
                    }
            //		for(int i=0; i<m; i++){
            //			for(int j=0; j<n;j++){
            //				cout << ruaskiri[i][j]<<"  ";
            //			}
            //			cout <<" = "<<ruaskanan[i];
            //			cout <<endl;
            //		}
                }
                //tampil matriks
                cout<< "\n   \n";
                for(int i=0; i<n; i++){
                    cout << "X"<<i+1<<" = "<<ruaskanan[i]<<endl;
                }
            }
            else if(pilih2==3){
                int n,bi;
                cout<<"Masukkan bentuk persamaan linear = ";
                cin>>n;
                bi=n;
                float A[n][n],B[bi][1],C[n][n];
                float jumlah,hasil[10][10]={0};
                float invers[10][10]={0};
                cout<<"Masukkan elemen matriks "<<endl;
                for(i=1;i<=n;i++){
                    for(j=1;j<=n;j++){
                        cin>>invers[i][j];
                    }
                }
                cout<<"Masukkan nilai bi"<<endl;
                for(i=1; i<=bi; i++){
                    for(j=1; j<=1; j++){
                        cin>>B[i][j];
                    }
                }

                for(i=1;i<=n;i++)
                    for(j=1;j<=2*n;j++)
                        if(j==(i+n))
                            invers[i][j]=1;

                for(i=n;i>1;i--)
                {
                    if(invers[i-1][1]<invers[i][1])
                    for(j=1;j<=n*2;j++)
                    {
                        det=invers[i][j];
                        invers[i][j]=invers[i-1][j];
                        invers[i-1][j]=det;
                    }
                }
                cout<<"OBE: "<<endl;
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n*2;j++)
                        cout<<invers[i][j]<<"    ";
                    cout<<endl;
                }

                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n*2;j++)
                    if(j!=i)
                    {
                        det=invers[j][i]/invers[i][i];
                        for(k=1;k<=n*2;k++)
                            invers[j][k]-=invers[i][k]*det;
                    }
                }

                for(i=1;i<=n;i++)
                {
                det=invers[i][i];
                    for(j=1;j<=n*2;j++)
                        invers[i][j]=invers[i][j]/det;
                }


                cout<<"Invers: "<<endl;
                for(i=1;i<=n;i++)
                {
                    for(j=n+1;j<=n*2;j++)
                        cout<<invers[i][j]<<"    ";
                    cout<<endl;
                }
                cout<<endl<<endl;
                for(i=1;i<=n;i++){
                    for(j=1;j<=n;j++){
                        invers[i][j]=invers[i][j+n];
                    }
                }


                if(n!= bi){
                    cout << "Matriks tidak bisa dikalikan";
                  } else {
                    for(i = 1; i <= n; i++){
                      for(j = 1; j <= 1; j++){
                        for(k = 1; k <= bi; k++){
                          jumlah = jumlah + invers[i][k] * B[k][j];
                        }
                        hasil[i][j] = jumlah;
                        jumlah = 0;
                      }
                    }
                    cout << "Nilai SPL X1, X2, X3, dan seterusnya adalah:"<<endl;
                    for(i = 1; i <= n; i++){
                      for(j = 1; j <= 1; j++){
                        cout << hasil[i][j] << "\t";
                      }
                      cout << endl;
                    }
                  }

            }
            else if(pilih2==4){
                int m,n,bi,u;
                cout<<"Masukkan bentuk persamaan linear = ";
                cin>>m;
                cout<<"Masukkan jumlah persamaan = ";
                cin>>n;
                float A[m][n],det0,det1,det2,det3;
                bi=n;
                float B[n][1];

                cout<<"Masukkan elemen matriks"<<endl;
                for(i=0; i<m; i++){
                    for(j=0; j<n; j++){
                        cin>>A[i][j];
                    }
                    cout<<endl;
                }
                cout<<endl;

                cout<<"Masukkan nilai bi"<<endl;
                for(i=0; i<n; i++){
                    for(j=0; j<1; j++){
                        cin>>B[i][j];
                    }
                }


                a=A[0][0];
                b=A[0][1];
                c=A[0][2];
                float C1,C2,C3;
                C1=A[1][1]*A[2][2]-A[1][2]*A[2][1];
                C2=(A[1][0]*A[2][2]-A[2][0]*A[1][2])*-1;
                C3=A[1][0]*A[2][1]-A[2][0]*A[1][1];
                det=a*C1+b*C2+c*C3;
                cout<<"Det= "<<det<<endl;


                for(u=1; u<=3;u++){
                if(u==1){
                for(i=0; i<m; i++){
                    for(j=0; j<n-2; j++){
                        A[i][j]=B[i][1];
                    }
                }
                a=A[0][0];
                b=A[0][1];
                c=A[0][2];
                C1=A[1][1]*A[2][2]-A[1][2]*A[2][1];
                C2=(A[1][0]*A[2][2]-A[2][0]*A[1][2])*-1;
                C3=A[1][0]*A[2][1]-A[2][0]*A[1][1];
                det1=a*C1+b*C2+c*C3;
                cout<<"Det1= "<<det1<<endl;
                }

                else if(u==2){
                for(i=0; i<m; i++){
                    for(j=1; j<n-1; j++){
                        A[i][j]=B[i][1];
                    }
                }
                a=A[0][0];
                b=A[0][1];
                c=A[0][2];
                C1=A[1][1]*A[2][2]-A[1][2]*A[2][1];
                C2=(A[1][0]*A[2][2]-A[2][0]*A[1][2])*-1;
                C3=A[1][0]*A[2][1]-A[2][0]*A[1][1];
                det2=a*C1+b*C2+c*C3;
                cout<<"Det2= "<<det2<<endl;
                }

                else if(u==3){
                for(i=0; i<m; i++){
                    for(j=2; j<n; j++){
                        A[i][j]=B[i][1];
                    }
                }
                a=A[0][0];
                b=A[0][1];
                c=A[0][2];
                C1=A[1][1]*A[2][2]-A[1][2]*A[2][1];
                C2=(A[1][0]*A[2][2]-A[2][0]*A[1][2])*-1;
                C3=A[1][0]*A[2][1]-A[2][0]*A[1][1];
                det3=a*C1+b*C2+c*C3;
                cout<<"Det3= "<<det3<<endl;
                }
                }

                cout<<"Nilai X1= "<<det1/det<<endl;
                cout<<"Nilai X2= "<<det2/det<<endl;
                if(n==3){
                cout<<"Nilai X3= "<<det3/det<<endl;
                }
            }
            else{
                exit(0);
            }

        }


        else if(pilih1==2){
            cout<<"1. Metode eliminasi Gauss"<<endl;
            cout<<"2. Metode kofaktor"<<endl;
            cout<<"Pilihan = ";
            cin>>pilih2;
            if(pilih2==1){
                int n, pangkat=0, temp;
                float A;
                cout << "Masukkan banyak ordo: ";
                cin >> n;
                float matriks[n][n];
                for(i=0; i<n; i++){
                    for(j=0; j<n;j++){
            //			cout << "A" << "["<<i+1<<"]["<<j+1<<"] : ";
                        cin >> matriks[i][j];
                    }
                }
            //	cout << "\n matriks augmented "<<endl;
            //	for(int i=0; i<n; i++){
            //		for(int j=0; j<n;j++){
            //			cout << matriks[i][j]<<"  ";
            //		}
            //		cout <<endl;
            //	}
            //	cout <<"Proses OBE matriks augmented";
                for(i=0; i<n; i++){
                    for(j=i+1; j<n; j++){
                        A = matriks[j][i] / matriks[i][i];
                        for(k=0; k<n;k++){
                            matriks[j][k] = matriks[j][k] - A*matriks[i][k];
                        }
                    }
                    pangkat++;
                }
                    cout <<"\n  \n";
                for(k=0;k<n;k++){
                    for(l=0;l<n;l++){
                        cout <<matriks[k][l]<<"  ";
                    }
                    cout <<"\n  \n";
                }

                cout << "Perhitungan determinan"<<endl;
                float determinan = 1;
                float sum;
                for (i=0; i<n; i++){
                    for (j=0; j<n; j++){
                        if(i == j){
                            determinan = determinan * matriks[i][j];
                        }
                    }
                }
                temp = pow(-1,pangkat);
                cout << temp *determinan*-1 ;
            }

            else if(pilih2==2){
                cout<<"Masukkan bentuk matriks persegi= ";
                cin>>n;
                int A[n][n];

                if(n==2){
                    float det=0,invers=0,temp;
                    for(i=0; i<n; i++){
                        for(j=0; j<n; j++){
                            cin>>A[i][j];
                        }
                    }

                    det=A[0][0]*A[1][1]-A[0][1]*A[1][0];
                    cout<<"Determinan : "<<det<<endl<<endl;
                }

                else if(n==3){
                    cout<<"Masukkan elemen matriks"<<endl;
                    for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                            cin>>A[i][j];
                        }
                        cout<<endl;
                    }

                    cout<<"\n";
                    //menghitung determinan
                    a=A[0][0];
                    b=A[0][1];
                    c=A[0][2];

                    float C1,C2,C3;

                    C1=A[1][1]*A[2][2]-A[1][2]*A[2][1];
                    C2=(A[1][0]*A[2][2]-A[2][0]*A[1][2])*-1;
                    C3=A[1][0]*A[2][1]-A[2][0]*A[1][1];

                    cout<<"C1="<<" "<<C1<<endl;
                    cout<<"C2="<<" "<<C2<<endl;
                    cout<<"C3="<<" "<<C3<<endl<<endl;

                    det=a*C1+b*C2+c*C3;

                    cout<<"Determinan A = "<<" ";
                    cout<<det;
                }

            }

            else{
                exit(0);
            }
        }

        else if(pilih1==3){
        	cout<<"Masukkan bentuk matriks persegi= ";
        	cin>>n;
            if(n==2){
                int A[n][n];
                float det=0,invers=0,temp;

                for(i=0; i<n; i++){
                    for(j=0; j<n; j++){
                        cin>>A[i][j];
                    }
                }

                det=A[0][0]*A[1][1]-A[0][1]*A[1][0];
                cout<<"Determinan : "<<det<<endl<<endl;

                cout<<"Invers: "<<endl;
                A[0][0]=temp;
                A[0][0]=A[1][1];
                temp=A[1][1];
                A[0][1]*=-1;
                A[1][0]*=-1;

                for(i=0; i<n; i++){
                    for(j=0; j<n; j++){
                        A[i][j]/=det;
                        if(i==0 && j==1){
                            cout<<A[i][j]<<endl;
                        }
                        else{
                            cout<<A[i][j]<<"  ";
                        }
                    }
                }

            }

            else if(n==3){
                int A[n][n];
                 float invers[10][10]={0};
                cout<<"Masukkan elemen matriks "<<endl;
                for(i=1;i<=n;i++)
                    for(j=1;j<=n;j++)
                        cin>>invers[i][j];

                for(i=1;i<=n;i++)
                    for(j=1;j<=2*n;j++)
                        if(j==(i+n))
                            invers[i][j]=1;

                for(i=n;i>1;i--)
                {
                    if(invers[i-1][1]<invers[i][1])
                    for(j=1;j<=n*2;j++)
                    {
                        det=invers[i][j];
                        invers[i][j]=invers[i-1][j];
                        invers[i-1][j]=det;
                    }
                }
                cout<<"OBE: "<<endl;
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n*2;j++)
                        cout<<invers[i][j]<<"    ";
                    cout<<endl;
                }

                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n*2;j++)
                    if(j!=i)
                    {
                        det=invers[j][i]/invers[i][i];
                        for(k=1;k<=n*2;k++)
                            invers[j][k]-=invers[i][k]*det;
                    }
                }

                for(i=1;i<=n;i++)
                {
                det=invers[i][i];
                    for(j=1;j<=n*2;j++)
                        invers[i][j]=invers[i][j]/det;
                }


                cout<<"Invers: "<<endl;
                for(i=1;i<=n;i++)
                {
                    for(j=n+1;j<=n*2;j++)
                        cout<<invers[i][j]<<"    ";
                    cout<<endl;
                }

            }
		}

    else{
            exit(0);
    }

    }

    cout<<"MENU"<<endl;
    cout <<endl;
        cout<<"1. Sistem Persamaan Linear"<<endl;
        cout<<"2. Determinan"<<endl;
        cout<<"3. Matriks balikan"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Pilihan = ";
        cin>>pilih1;
        if(pilih1==1){
            cout<<endl;
            cout<<"1. Metode eliminasi Gauss"<<endl;
            cout<<"2. Metode eliminasi Gaus-Jordan"<<endl;
            cout<<"3. Metode matriks balikan"<<endl;
            cout<<"4. Kaidah Cramer"<<endl;
            cout<<"Pilihan = ";
            cin>>pilih2;

            if(pilih2==1){
                int n, m;
                float A;
                cout << "Masukkan banyak variabel : ";
                cin >> n;
                cout << "Masukkan banyak persamaan : ";
                cin >> m;
                float ruaskiri[m][n+1];
                float ruaskanan[m];
                for(int i=0; i<m; i++){
                    for(int j=0; j<=n;j++){
                        if(j==n){
            //				cout <<"B["<<i+1<<"] : ";
                            cin >> ruaskiri[i][j];
                        }else{
            //				cout << "A" << "["<<i+1<<"]["<<j+1<<"] : ";
                            cin >> ruaskiri[i][j];
                        }
                    }
                }
                for(int i=0; i<m; i++){
                    for(int j=0; j<=n;j++){
                        if(j==n){
                            cout<<" = "<<ruaskiri[i][j]<<endl;
                        }else{
                            cout << ruaskiri[i][j]<<"x"<<j+1<<"  ";
                        }
                    }
                    cout<<endl;
                }
            //	cout << "\n matriks augmented "<<endl;
            //	for(int i=0; i<m; i++){
            //		for(int j=0; j<n+1;j++){
            //			cout << ruaskiri[i][j]<<"  ";
            //		}
            //		cout <<endl;
            //	}
            //	cout <<"Proses OBE matriks augmented";
                for(int i=0; i<n-1; i++){
                    for(int j=i+1; j<n; j++){
                        A = ruaskiri[j][i] / ruaskiri[i][i];
                        for(int k=0; k<n+1;k++){
                            ruaskiri[j][k] = ruaskiri[j][k] - A*ruaskiri[i][k];
                        }
                    }
                }
                    cout <<"\n  \n";
            //	for(int k=0;k<n;k++){
            //		for(int l=0;l<n;l++){
            //			cout <<ruaskiri[k][l]<<"  ";
            //		}
            //		cout<< ruaskiri[k][n]<<"  ";
            //		cout <<"\n  \n";
            //	}
                for(int k=0; k<n; k++){
                    ruaskanan[k]=ruaskiri[k][n];
                }
                //penghitungan x
                float temp;
                float Z[10];

                temp = ruaskiri[m-1][n-1];
                Z[m-1]=ruaskanan[m-1]/temp;

                for (int i=(n-2);i>=0;i--){
                    temp=ruaskiri[i][i];
                    for(int j=i+1; j<n; j++){
                        ruaskanan[i] =ruaskanan[i] - (ruaskiri[i][j]*Z[j]);
                    }
                    Z[i]=ruaskanan[i]/temp;
                }
                cout <<"\n Setelaah pengurutan dan perhitungan \n";
                for(int i=0; i<(n); i++){
                    cout <<"X"<<i+1<<" = "<<Z[i] <<endl;
                }
            }
            else if(pilih2==2){
                int n, m;
                float A;
                cout << "Masukkan banyak variabel : ";
                cin >> n;
                cout << "Masukkan banyak persamaan : ";
                cin >> m;
                float ruaskiri[m][n+1];
                float ruaskanan[m];
                for(int i=0; i<m; i++){
                    for(int j=0; j<=n;j++){
                        if(j==n){
            //				cout <<"B["<<i+1<<"] : ";
                            cin >> ruaskiri[i][j];
                        }else{
            //				cout << "A" << "["<<i+1<<"]["<<j+1<<"] : ";
                            cin >> ruaskiri[i][j];
                        }
                    }
                }
                for(int i=0; i<m; i++){
                    for(int j=0; j<=n;j++){
                        if(j==n){
                            cout<<" = "<<ruaskiri[i][j]<<endl;
                        }else{
                            cout << ruaskiri[i][j]<<"X"<<j+1<<"  ";
                        }
                    }
                    cout<<endl;
                }
            //	cout << "\n matriks augmented "<<endl;
            //	for(int i=0; i<m; i++){
            //		for(int j=0; j<n+1;j++){
            //			cout << ruaskiri[i][j]<<"  ";
            //		}
            //		cout <<endl;
            //	}
                for(int k=0; k<n; k++){
                    ruaskanan[k]=ruaskiri[k][n];
                }
                //penyelesaian gausjordan
                float temp;
                for(int i=0; i<n; i++){
                    //cout <<"\nTahap "<<i+1<<endl;
                    temp=ruaskiri[i][i];
                    for(int j=0; j<n; j++){
                        ruaskiri[i][j]=ruaskiri[i][j]/temp;
                    }
                    ruaskanan[i]=ruaskanan[i]/temp;
                    for(int k=0;k<n;k++){
                        if(k!=i){
                            temp=ruaskiri[k][i];
                            for(int j=0;j<n;j++){
                                ruaskiri[k][j]= ruaskiri[k][j]-(temp * ruaskiri[i][j]);
                            }
                            ruaskanan[k]=ruaskanan[k]-(temp*ruaskanan[i]);
                        }
                    }
            //		for(int i=0; i<m; i++){
            //			for(int j=0; j<n;j++){
            //				cout << ruaskiri[i][j]<<"  ";
            //			}
            //			cout <<" = "<<ruaskanan[i];
            //			cout <<endl;
            //		}
                }
                //tampil matriks
                cout<< "\n   \n";
                for(int i=0; i<n; i++){
                    cout << "X"<<i+1<<" = "<<ruaskanan[i]<<endl;
                }
            }
            else if(pilih2==3){
                int n,bi;
                cout<<"Masukkan bentuk persamaan linear = ";
                cin>>n;
                bi=n;
                float A[n][n],B[bi][1],C[n][n];
                float jumlah,hasil[10][10]={0};
                float invers[10][10]={0};
                cout<<"Masukkan elemen matriks "<<endl;
                for(i=1;i<=n;i++){
                    for(j=1;j<=n;j++){
                        cin>>invers[i][j];
                    }
                }
                cout<<"Masukkan nilai bi"<<endl;
                for(i=1; i<=bi; i++){
                    for(j=1; j<=1; j++){
                        cin>>B[i][j];
                    }
                }

                for(i=1;i<=n;i++)
                    for(j=1;j<=2*n;j++)
                        if(j==(i+n))
                            invers[i][j]=1;

                for(i=n;i>1;i--)
                {
                    if(invers[i-1][1]<invers[i][1])
                    for(j=1;j<=n*2;j++)
                    {
                        det=invers[i][j];
                        invers[i][j]=invers[i-1][j];
                        invers[i-1][j]=det;
                    }
                }
                cout<<"OBE: "<<endl;
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n*2;j++)
                        cout<<invers[i][j]<<"    ";
                    cout<<endl;
                }

                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n*2;j++)
                    if(j!=i)
                    {
                        det=invers[j][i]/invers[i][i];
                        for(k=1;k<=n*2;k++)
                            invers[j][k]-=invers[i][k]*det;
                    }
                }

                for(i=1;i<=n;i++)
                {
                det=invers[i][i];
                    for(j=1;j<=n*2;j++)
                        invers[i][j]=invers[i][j]/det;
                }


                cout<<"Invers: "<<endl;
                for(i=1;i<=n;i++)
                {
                    for(j=n+1;j<=n*2;j++)
                        cout<<invers[i][j]<<"    ";
                    cout<<endl;
                }
                cout<<endl<<endl;
                for(i=1;i<=n;i++){
                    for(j=1;j<=n;j++){
                        invers[i][j]=invers[i][j+n];
                    }
                }


                if(n!= bi){
                    cout << "Matriks tidak bisa dikalikan";
                  } else {
                    for(i = 1; i <= n; i++){
                      for(j = 1; j <= 1; j++){
                        for(k = 1; k <= bi; k++){
                          jumlah = jumlah + invers[i][k] * B[k][j];
                        }
                        hasil[i][j] = jumlah;
                        jumlah = 0;
                      }
                    }
                    cout << "Nilai SPL X1, X2, X3, dan seterusnya adalah:"<<endl;
                    for(i = 1; i <= n; i++){
                      for(j = 1; j <= 1; j++){
                        cout << hasil[i][j] << "\t";
                      }
                      cout << endl;
                    }
                  }

            }
            else if(pilih2==4){
                int m,n,bi,u;
                cout<<"Masukkan bentuk persamaan linear = ";
                cin>>m;
                cout<<"Masukkan jumlah persamaan = ";
                cin>>n;
                float A[m][n],det0,det1,det2,det3;
                bi=n;
                float B[n][1];

                cout<<"Masukkan elemen matriks"<<endl;
                for(i=0; i<m; i++){
                    for(j=0; j<n; j++){
                        cin>>A[i][j];
                    }
                    cout<<endl;
                }
                cout<<endl;

                cout<<"Masukkan nilai bi"<<endl;
                for(i=0; i<n; i++){
                    for(j=0; j<1; j++){
                        cin>>B[i][j];
                    }
                }


                a=A[0][0];
                b=A[0][1];
                c=A[0][2];
                float C1,C2,C3;
                C1=A[1][1]*A[2][2]-A[1][2]*A[2][1];
                C2=(A[1][0]*A[2][2]-A[2][0]*A[1][2])*-1;
                C3=A[1][0]*A[2][1]-A[2][0]*A[1][1];
                det=a*C1+b*C2+c*C3;
                cout<<"Det= "<<det<<endl;


                for(u=1; u<=3;u++){
                if(u==1){
                for(i=0; i<m; i++){
                    for(j=0; j<n-2; j++){
                        A[i][j]=B[i][1];
                    }
                }
                a=A[0][0];
                b=A[0][1];
                c=A[0][2];
                C1=A[1][1]*A[2][2]-A[1][2]*A[2][1];
                C2=(A[1][0]*A[2][2]-A[2][0]*A[1][2])*-1;
                C3=A[1][0]*A[2][1]-A[2][0]*A[1][1];
                det1=a*C1+b*C2+c*C3;
                cout<<"Det1= "<<det1<<endl;
                }

                else if(u==2){
                for(i=0; i<m; i++){
                    for(j=1; j<n-1; j++){
                        A[i][j]=B[i][1];
                    }
                }
                a=A[0][0];
                b=A[0][1];
                c=A[0][2];
                C1=A[1][1]*A[2][2]-A[1][2]*A[2][1];
                C2=(A[1][0]*A[2][2]-A[2][0]*A[1][2])*-1;
                C3=A[1][0]*A[2][1]-A[2][0]*A[1][1];
                det2=a*C1+b*C2+c*C3;
                cout<<"Det2= "<<det2<<endl;
                }

                else if(u==3){
                for(i=0; i<m; i++){
                    for(j=2; j<n; j++){
                        A[i][j]=B[i][1];
                    }
                }
                a=A[0][0];
                b=A[0][1];
                c=A[0][2];
                C1=A[1][1]*A[2][2]-A[1][2]*A[2][1];
                C2=(A[1][0]*A[2][2]-A[2][0]*A[1][2])*-1;
                C3=A[1][0]*A[2][1]-A[2][0]*A[1][1];
                det3=a*C1+b*C2+c*C3;
                cout<<"Det3= "<<det3<<endl;
                }
                }

                cout<<"Nilai X1= "<<det1/det<<endl;
                cout<<"Nilai X2= "<<det2/det<<endl;
                if(n==3){
                cout<<"Nilai X3= "<<det3/det<<endl;
                }
            }
            else{
                exit(0);
            }

        }


        else if(pilih1==2){
            cout<<"1. Metode eliminasi Gauss"<<endl;
            cout<<"2. Metode kofaktor"<<endl;
            cout<<"Pilihan = ";
            cin>>pilih2;
            if(pilih2==1){
                int n, pangkat=0, temp;
                float A;
                cout << "Masukkan banyak ordo: ";
                cin >> n;
                float matriks[n][n];
                for(i=0; i<n; i++){
                    for(j=0; j<n;j++){
            //			cout << "A" << "["<<i+1<<"]["<<j+1<<"] : ";
                        cin >> matriks[i][j];
                    }
                }
            //	cout << "\n matriks augmented "<<endl;
            //	for(int i=0; i<n; i++){
            //		for(int j=0; j<n;j++){
            //			cout << matriks[i][j]<<"  ";
            //		}
            //		cout <<endl;
            //	}
            //	cout <<"Proses OBE matriks augmented";
                for(i=0; i<n; i++){
                    for(j=i+1; j<n; j++){
                        A = matriks[j][i] / matriks[i][i];
                        for(k=0; k<n;k++){
                            matriks[j][k] = matriks[j][k] - A*matriks[i][k];
                        }
                    }
                    pangkat++;
                }
                    cout <<"\n  \n";
                for(k=0;k<n;k++){
                    for(l=0;l<n;l++){
                        cout <<matriks[k][l]<<"  ";
                    }
                    cout <<"\n  \n";
                }

                cout << "Perhitungan determinan"<<endl;
                float determinan = 1;
                float sum;
                for (i=0; i<n; i++){
                    for (j=0; j<n; j++){
                        if(i == j){
                            determinan = determinan * matriks[i][j];
                        }
                    }
                }
                temp = pow(-1,pangkat);
                cout << temp *determinan*-1 ;
            }

            else if(pilih2==2){
                cout<<"Masukkan bentuk matriks persegi= ";
                cin>>n;
                int A[n][n];

                if(n==2){
                    float det=0,invers=0,temp;
                    for(i=0; i<n; i++){
                        for(j=0; j<n; j++){
                            cin>>A[i][j];
                        }
                    }

                    det=A[0][0]*A[1][1]-A[0][1]*A[1][0];
                    cout<<"Determinan : "<<det<<endl<<endl;
                }

                else if(n==3){
                    cout<<"Masukkan elemen matriks"<<endl;
                    for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                            cin>>A[i][j];
                        }
                        cout<<endl;
                    }

                    cout<<"\n";
                    //menghitung determinan
                    a=A[0][0];
                    b=A[0][1];
                    c=A[0][2];

                    float C1,C2,C3;

                    C1=A[1][1]*A[2][2]-A[1][2]*A[2][1];
                    C2=(A[1][0]*A[2][2]-A[2][0]*A[1][2])*-1;
                    C3=A[1][0]*A[2][1]-A[2][0]*A[1][1];

                    cout<<"C1="<<" "<<C1<<endl;
                    cout<<"C2="<<" "<<C2<<endl;
                    cout<<"C3="<<" "<<C3<<endl<<endl;

                    det=a*C1+b*C2+c*C3;

                    cout<<"Determinan A = "<<" ";
                    cout<<det;
                }

            }

            else{
                exit(0);
            }
        }

        else if(pilih1==3){
        	cout<<"Masukkan bentuk matriks persegi= ";
        	cin>>n;
            if(n==2){
                int A[n][n];
                float det=0,invers=0,temp;

                for(i=0; i<n; i++){
                    for(j=0; j<n; j++){
                        cin>>A[i][j];
                    }
                }

                det=A[0][0]*A[1][1]-A[0][1]*A[1][0];
                cout<<"Determinan : "<<det<<endl<<endl;

                cout<<"Invers: "<<endl;
                A[0][0]=temp;
                A[0][0]=A[1][1];
                temp=A[1][1];
                A[0][1]*=-1;
                A[1][0]*=-1;

                for(i=0; i<n; i++){
                    for(j=0; j<n; j++){
                        A[i][j]/=det;
                        if(i==0 && j==1){
                            cout<<A[i][j]<<endl;
                        }
                        else{
                            cout<<A[i][j]<<"  ";
                        }
                    }
                }

            }

            else if(n==3){
                int A[n][n];
                 float invers[10][10]={0};
                cout<<"Masukkan elemen matriks "<<endl;
                for(i=1;i<=n;i++)
                    for(j=1;j<=n;j++)
                        cin>>invers[i][j];

                for(i=1;i<=n;i++)
                    for(j=1;j<=2*n;j++)
                        if(j==(i+n))
                            invers[i][j]=1;

                for(i=n;i>1;i--)
                {
                    if(invers[i-1][1]<invers[i][1])
                    for(j=1;j<=n*2;j++)
                    {
                        det=invers[i][j];
                        invers[i][j]=invers[i-1][j];
                        invers[i-1][j]=det;
                    }
                }
                cout<<"OBE: "<<endl;
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n*2;j++)
                        cout<<invers[i][j]<<"    ";
                    cout<<endl;
                }

                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n*2;j++)
                    if(j!=i)
                    {
                        det=invers[j][i]/invers[i][i];
                        for(k=1;k<=n*2;k++)
                            invers[j][k]-=invers[i][k]*det;
                    }
                }

                for(i=1;i<=n;i++)
                {
                det=invers[i][i];
                    for(j=1;j<=n*2;j++)
                        invers[i][j]=invers[i][j]/det;
                }


                cout<<"Invers: "<<endl;
                for(i=1;i<=n;i++)
                {
                    for(j=n+1;j<=n*2;j++)
                        cout<<invers[i][j]<<"    ";
                    cout<<endl;
                }

            }
		}

    else{
            exit(0);
    }
}
