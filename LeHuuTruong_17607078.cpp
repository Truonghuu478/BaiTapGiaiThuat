#include <iostream>
#include <cstdlib>
#include <random>
#include<time.h>
#include <math.h>
#define max 100
using namespace std;
void xuatMang(int arr[], int daim)
{
   cout << "\narr = [";
   for (int i = 0; i < daim; i++)
   {
      (i == daim - 1) ? cout << arr[i] << "" : cout << arr[i] << " ;";
   }
   cout << "]\n";
}
void kiemTraX(int arr[], int x, int daim)
{
   for (int i = 0; i < daim; i++)

   {
      if(x < arr[i]) cout << arr[i] << ", ";
   }
}
void kiemTraY(int arr[], int y, int daim)
{
   for (int i = 0; i < daim; i++)
   {
     if(y > arr[i]) cout << arr[i] << ", " ;
   }
}

void lietKeMVaN(int arr[], int &daim)
{
   signed int x,y;
   cout << "\nNhập X : ";
   cin >> x;
   cout << "\nNhập Y : ";
   cin >> y;
   cout << "\nCac gia tri < m : ";
   kiemTraX(arr, x, daim);
   cout << "\ncac gia tri > n : ";
   kiemTraY(arr,y, daim);
}
void timGiaTriLonVaNhoNhat(int arr[], int &daim)
{
   int m = -1;
   for (int i = 0; i < daim; i++)
   {
      if (arr[i] < 0)
      {
         m = i;
         break;
      }
   }
   if (m != -1)
   {
      for (int i = 1; i < daim; i++)
      {
         if (arr[i] < 0 && arr[m] < arr[i])
         {
            m = i;
         }
      }
      cout << "Vi tri co so am lon nhat la : " << m;
   }
   else
      cout << "Mang khong co so am";
}
bool kiemTraSoHT(int x)
{
   int i, tong = 0;
   for (i = 1; i < x; i++)
      if (x % i == 0)
         tong = tong + i;
   if (tong == x)
      return true;
   return false;
}
void timSoHT(int arr[], int &daim)
{
   int dem = 0;
   for (int i = 0; i < daim; i++)
   {
      if (kiemTraSoHT(arr[i]) == true)
      {
         dem++;
      }
   }
   if (dem == 0)
   {
      cout << "Mang khong co so hoan thien !!!";
   }else cout << "Mang co " << dem << " so hoan thien .";
}
bool timSoNguyenTo(int x)
{

   if (x < 2)
   {
      return false;
   }
   for (int i = 2; i < x; i++)
   {

      if (x % i == 0)
      {
         return false;
      }
   }

   return true;
}
void TongSoNguyenTo(int arr[], int &daim)
{

   int tong = 0;
   for (int i = 0; i < daim; i++)
   {
      if (timSoNguyenTo(arr[i]) == true)
      {
         tong += arr[i];
      }
   }
   cout << "\nTong so nguyen to : " << tong << endl;
}
bool kiemTraTangDan(int arr[], int &daim)
{

   for (int i = 0; i < daim; i++)
   {
      if (arr[i + 1] < arr[i])
         return false;
   }
   return true;
}
void xoa1Phantu(int arr[], int &n, int vitrixoa)
{
   for (int i = vitrixoa; i < n; i++)
   {
      arr[i] = arr[i + 1];
   }
   n--;
}

void xoaGiaTriAm(int arr[], int &daim)
{
   for (int i = 0; i < daim; i++)
   {

      if (arr[i] < 0)
      {
         xoa1Phantu(arr, daim, i);
         i--;
      }
   }
}
void themPhanTu(int arr[], int &daim, int x, int viTri)
{

   for (int i = daim - 1; i >= viTri; i--){
      arr[i+1] = arr[i];
   }
   arr[viTri] = x;
   daim++;
}
void themXvaoPhanTu(int arr[], int &daim, int x)
{
   for (int i = 0; i < daim; i++)
   {
      if (arr[i] %2 != 0)
      {
         themPhanTu(arr, daim, x,i+1);
      }
   }
}

void xapXep(int arr[], int &daim){
   signed int min = 0, tmp, j, chan = 0, k = 0;
   for (int i = 0; i < daim; i++)
   {
      if (arr[i] % 2 == 0)
      {
         k = i;
         for (j = 0; j < daim; j++)
         {
            tmp = arr[k];
            arr[k] = arr[j];
            arr[j] = tmp;
         }
         i--;
      }
   };
   for (int i = 0; i < daim; i++)
   {
      if (arr[i] % 2 == 0)
      {
         min = i;
         for (j = i + 1; j < daim; j++)
            if (arr[min] > arr[j] && arr[j] % 2 == 0)
               min = j;
         tmp = arr[min];
         arr[min] = arr[i];
         arr[i] = tmp;
      }
      else
      {
         min = i;
         for (j = i + 1; j < daim; j++)
            if (arr[min] < arr[j] && arr[j] % 2 != 0)
               min = j;
         tmp = arr[min];
         arr[min] = arr[i];
         arr[i] = tmp;
      }
   };
   
}
void xoaTrung(int arr[],int &daim){
   int j,k;
   for (int i = 0; i < daim; i++)
   {
      j=i+1;
      while (i<daim)
      {
        if(arr[i] == arr[j]){
           for (k = j; i < daim; k++) arr[k]=arr[k+1];
           daim--;
        }else
        {
           j=j+1;
        } 
      }  
   }
}
void menu()
{
   cout << "\n\n----------------------------menu---------------------------\n";
   cout << "\n0. Thoat\n";
   cout << "\n1. Liet ke cac phan tu lon hon x va nho hon y \n";
   cout << "\n2. Tim vi tri phan tu co gia tri la so am lon nhat.\n";
   cout << "\n3. Đem so luong cac phan tu co gia tri là so hoan thien co trong mang.\n";
   cout << "\n4. Tinh tong cac phan tu co gia tri la so nguyen to co trong mang.\n";
   cout << "\n5. Kiem tra xem mang co tang dan hay khong ?\n";
   cout << "\n6. Xoa tat ca cac phan tu co gia tri am co trong mang.\n";
   cout << "\n7. Thêm X sau tất cả các phần tử có giá trị lẻ trong mảng.\n";
   cout << "\n8. Sap xep cac phan tu gia tri chan o đau mang tang dan, cac phan tu co gia tri le o cuoi mang giam dan \n";
   cout <<"\n9. Xoa cac phan tu trung nhau(lam them ) .\n";
   cout << "\nLua Chon : ";
}
void xuLy(int arr[], int &daim, int chon)
{
   switch (chon)
   {
   case 1:
      cout << "\nCau 1 : \n";
      lietKeMVaN(arr, daim);
      break;
   case 2:
      cout << "\nCau 2 : \n";
      timGiaTriLonVaNhoNhat(arr, daim);
      break;
   case 3:
      cout << "\nCau 3 : \n";
      timSoHT(arr, daim);
      break;
   case 4:
      cout << "\nCau 4 : \n";
      TongSoNguyenTo(arr, daim);
      break;
   case 5:
      cout << "\nCau 5 : \n";
      if (kiemTraTangDan(arr, daim) == true)
      {
         cout << "Mang co tang dan !!!";
      }
      else
         cout << "Mang khong tang dan!!!";
      break;
   case 6:
      cout << "Cau 6 : \n";
      xoaGiaTriAm(arr, daim);
      cout << "Mang sau khi xoa so am : ";
      xuatMang(arr, daim);
      break;
   case 7:
      cout << "Cau 7 : \n";
      int x;
      cout << "nhap X : ";
      cin >> x;
      themXvaoPhanTu(arr, daim, x);
      xuatMang(arr, daim);
      break;
   case 8: 
      cout<<"Cau 8 : ";
      xapXep(arr,daim);
      xuatMang(arr,daim);
      break;
   case 9:
      cout<<"Cau 9 : ";
      xoaTrung(arr,daim);
      xuatMang(arr,daim);
   default:
      break;
   }
}
void quanLy()
{
    int arr[max];
   int daim, chon = -1;
   cout<<"Le Huu Truong - 17607078 \n";
   cout << "Nhập số phần tử : ";
   cin >> daim;
   // Cach 1: 
   //  random_device rd;
   // mt19937 k(rd());  
   // uniform_int_distribution<int> uni(-50, 50);

   // cout << "arr=[";
   // for (int i = 0; i < daim; i++)
   // {
   //    arr[i] = uni(k);
   //    (i == daim - 1) ? cout << arr[i] << " " : cout << arr[i] << "; ";
   // }
   // cout << "]" << endl;

   // cach 2: 
   srand(time(NULL));
   cout << "arr=[";

   for (int i = 0; i < daim; i++)
   {
   int dau = rand()&1?-1:1;
   arr[i] = dau *(rand() %-51);
      i == daim - 1 ? cout << arr[i] << " " : cout << arr[i] << "; ";
   }
    cout << "]" << endl;
   do
   {
      menu();
      cin >> chon;
      xuLy(arr, daim, chon);
   } while (chon != 0);
}
int main()
{
  quanLy();
  return 0;

}

