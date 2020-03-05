#include <iostream>
#include <cstdlib>
#include <random>
#include <math.h>
#define max 100
using namespace std;
void xuatMang(int arr[], int Size)
{
   cout << "\narr = [";
   for (int i = 0; i < Size; i++)
   {
      (i == Size - 1) ? cout << arr[i] << "" : cout << arr[i] << " ;";
   }
   cout << "]\n";
}
void kiemTraM(int arr[], int m, int Size)
{
   for (int i = 0; i < Size; i++)

   {
      (m < arr[i]) ? cout << arr[i] << ", " : cout << arr[i] << ".";
   }
}
void kiemTraN(int arr[], int n, int Size)
{
   for (int i = 0; i < Size; i++)
   {
      (n > arr[i]) ? cout << arr[i] << ", " : cout << arr[i] << ".";
   }
}

void lietKeMVaN(int arr[], int Size)
{
   signed int m, n;
   cout << "\nNhập  m : ";
   cin >> m;
   cout << "\nNhập  n: ";
   cin >> n;
   cout << "\nCác giá trị < m : ";
   kiemTraM(arr, m, Size);
   cout << "\nCác giá trị nhỏ > n : ";
   kiemTraN(arr, n, Size);
}
void timGiaTriLonVaNhoNhat(int arr[], int Size)
{
   int m = -1;
   for (int i = 0; i < Size; i++)
   {
      if (arr[i] < 0)
      {
         m = i;
         break;
      }
   }
   if (m != -1)
   {
      for (int i = 1; i < Size; i++)
      {
         if (arr[i] < 0 && arr[m] < arr[i])
         {
            m = i;
         }
      }
      cout << "Số âm lớn nhất là : " << arr[m];
   }
   else
      cout << "mảng không có số âm";
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
void timSoHT(int arr[], int Size)
{
   int dem = 0;
   for (int i = 0; i < Size; i++)
   {
      if (kiemTraSoHT(arr[i]) == true)
      {
         dem++;
         cout << arr[i];
      }
   }
   if (dem == 0)
   {
      cout << "Mảng không có số hoàn thiện !!!";
   }
   cout << "Mảng có" << dem << " số hoàn thiện .";
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
void TongSoNguyenTo(int arr[], int Size)
{

   int tong = 0;
   for (int i = 0; i < Size; i++)
   {
      if (timSoNguyenTo(arr[i]) == true)
      {
         tong += arr[i];
      }
   }
   cout << "\nTổng số  nguyên tố : " << tong << endl;
}
bool kiemTraTangDan(int arr[], int Size)
{

   for (int i = 0; i < Size; i++)
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

void xoaGiaTriAm(int arr[], int &Size)
{
   for (int i = 0; i < Size; i++)
   {

      if (arr[i] < 0)
      {
         xoa1Phantu(arr, Size, i);
         i--;
      }
   }
}
void themPhanTu(int arr[], int &Size, int x, int viTri)
{

   for (int i = Size - 1; i >= viTri; i--)
   {
      arr[i + 1] = arr[i];
   }
   arr[viTri] = x;
   Size++;
}
void themXvaoPhanTu(int arr[], int &Size, int x)
{
   for (int i = 0; i < Size; i++)
   {
      if (arr[i] % 2 != 0)
      {
         themPhanTu(arr, Size, x, i + 1);
      }
   }
}

void xapXep(int arr[], int &Size)
{
   int min = 0, tmp, j, i, chan = 0, k = 0;
   for (int i = 0; i < Size; i++)
   {
      if (arr[i] % 2 == 0)
      {
         k = i;
         for (j = 0; j < Size; j++)
         {
            tmp = arr[k];
            arr[k] = arr[j];
            arr[j] = tmp;
         }
         i--;
      }
   };
   for (int i = 0; i < Size; i++)
   {
      if (arr[i] % 2 == 0)
      {
         min = i;
         for (j = i + 1; j < Size; j++)
            if (arr[min] > arr[j] && arr[j] % 2 == 0)
               min = j;
         tmp = arr[min];
         arr[min] = arr[i];
         arr[i] = tmp;
      }
      else
      {
         min = i;
         for (j = i + 1; j < Size; j++)
            if (arr[min] < arr[j] && arr[j] % 2 != 0)
               min = j;
         tmp = arr[min];
         arr[min] = arr[i];
         arr[i] = tmp;
      }
   };
   for (int i = 0; i < Size; i++)
   {
      printf("\n%d", arr[i]);
   };
}
void xoaTrung(int arr[],int &Size){
   int i,j,k;
   for (int i = 0; i < Size; i++)
   {
      j=i+1;
      while (i<Size)
      {
        if(arr[i] == arr[j]){
           for (k = j; i < Size; k++) arr[k]=arr[k+1];
           Size--;
        }else
        {
           j=j+1;
        }
        
      }
      
   }
   
}
void menu()
{
   cout << "\n\n-------------------------------------------menu---------------------------------------------------\t\t\t\n";
   cout << "\n0. Out\n";
   cout << "\n1. Liệt kê các phần tử có giá trị lớn hơn x và nhỏ hơn y. Với x và y là 2 giá trị do người dung nhập.\n";
   cout << "\n2. Tìm vị trí phần tử có giá trị là số âm lớn nhất.\n";
   cout << "\n3. Đếm số lượng các phần tử có giá trị là số hoàn thiện có trong mảng.\n";
   cout << "\n4. Tính tổng các phần tử có giá trị là số nguyên tố có trong mảng.\n";
   cout << "\n5. Kiểm tra xem mảng có tăng dần hay không?\n";
   cout << "\n6. Xóa tất cả các phần tử có giá trị âm có trong mảng.\n";
   cout << "\n7. Thêm X sau tất cả các phần tử có giá trị lẻ trong mảng.\n";
   cout << "\n8. Sắp xếp các phần tử  giá trị chẵn ở đầu mảng tăng dần, các phần tử có giá trị lẻ ở cuối mảng giảm dần \n";
   cout <<"\n9. Xóa các phần tử trùng nhau(làm thêm ) .\n";
   cout << "\nLựa chọn : ";
}
void xuLy(int arr[], int &Size, int chon)
{
   switch (chon)
   {
   case 1:
      cout << "\nCâu 1 : \n";
      lietKeMVaN(arr, Size);
      break;
   case 2:
      cout << "\nCâu 2 : \n";
      timGiaTriLonVaNhoNhat(arr, Size);
      break;
   case 3:
      cout << "\nCâu 3 : \n";
      timSoHT(arr, Size);
      break;
   case 4:
      cout << "\nCâu 4 : \n";
      TongSoNguyenTo(arr, Size);
      break;
   case 5:
      cout << "\nCâu 5 : \n";
      if (kiemTraTangDan(arr, Size) == true)
      {
         cout << "Mảng có tăng dần !!!";
      }
      else
         cout << "Mảng không tăng dần!!!";
      break;
   case 6:
      cout << "Câu 6 : \n";
      xoaGiaTriAm(arr, Size);
      cout << "Mảng sau khi xóa số âm : ";
      xuatMang(arr, Size);
      break;
   case 7:
      cout << "Câu 7 : \n";
      int x;
      cout << "nhập X : ";
      cin >> x;
      themXvaoPhanTu(arr, Size, x);
      xuatMang(arr, Size);
      break;
   case 8: 
      cout<<"Câu 8 : ";
      xapXep(arr,Size);
      xuatMang(arr,Size);
      break;
   case 9:
      cout<<"Câu 9 : ";
      xoaTrung(arr,Size);
      xuatMang(arr,Size);
   default:
      break;
   }
}
void quanLy()
{
   int arr[max];
   int Size, chon = -1;
   cout << "Nhập số phần tử : ";
   cin >> Size;
   random_device rd;
   mt19937 size(rd());
   uniform_int_distribution<int> uni(-50, 50);

   cout << "arr=[";
   for (int i = 0; i < Size; i++)
   {
      arr[i] = uni(size);
      (i == Size - 1) ? cout << arr[i] << " " : cout << arr[i] << "; ";
   }
   cout << "]" << endl;
   do
   {
      menu();
      cin >> chon;
      xuLy(arr, Size, chon);
   } while (chon != 0);
}
int main()
{
   quanLy();
   return 0;
}

