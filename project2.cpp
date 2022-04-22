#include <iostream>
using namespace std;
enum OS
{
  iOS = 0,
  Android = 1,
  windowsphone = 2
};
enum Color
{
  black = 0,
  white,
  blue,
  pink
};
enum Ram
{
  twoGB = 0,
  fourGB,
  sixGB,
  eightGB,
  twelveGB,
  sixteenGB,
  thirtytwoGB,
  fourtytwoGB
};
enum Storage
{
  sixtenGB = 0,
  thirtitwoGB,
  fourtitwoGB,
  onetwoeightGB,
  twofivesixGB,
  fiveonetwoGB,
  oneTB,
  twoTB
};
struct phone
{
  string name;
  string company;
  long long price;
  int exist = 0;
  int salled = 0;
  OS type;
  Color color;
  Ram ram;
  Storage storage;
};

void add_phone(phone *&, int &);
void show(phone *, int);
void show_os(phone *, int);
void show_color(phone *, int);
void show_ram(phone *, int);
void show_storage(phone *, int);
void reallocate(phone *&, int &);
void remove_phone(phone *&, int &);
int search(string, string, phone *, int);
void search_phone(phone *, int);
void change_mobile_info(phone *&, int);
void change_name(phone *&, int);
void change_company(phone *&, int);
void change_price(phone *&, int);
void sell_a_phone(phone *&, int);
void sort_by_price(phone *&, int);
void most_sold_items(phone *, int);
void get_OS(phone *&, int);
void get_color(phone *&, int);
void get_ram(phone *&, int);
void get_storage(phone *&, int);
int main()
{
  int size = 0;
  int answer = 0;
  bool showmenue = true;
  phone *variety = new phone[size];
  while (showmenue)
  {
    cout << "1- Add a phone" << '\n';
    cout << "2- Remove a phone" << '\n';
    cout << "3- Sort phones by price" << '\n';
    cout << "4- Search a phone" << '\n';
    cout << "5- Change mobile info" << '\n';
    cout << "6- Sell a phone" << '\n';
    cout << "7- Print phones" << '\n';
    cout << "8- Print phones sorted by the most sold to the least" << '\n';
    cout << "9- Quit" << '\n';
    cin >> answer;
    switch (answer)
    {
    case 1:
      add_phone(variety, size);
      break;
    case 2:
      remove_phone(variety, size);
      break;
    case 3:
      sort_by_price(variety, size);
      break;
    case 4:
      search_phone(variety, size);
      break;
    case 5:
      change_mobile_info(variety, size);
      break;
    case 6:
      sell_a_phone(variety, size);
      break;
    case 7:
      show(variety, size);
      break;
    case 8:
      most_sold_items(variety, size);
      break;
    case 9:
      showmenue = false;
      delete[] variety;
      break;
    default:
      break;
    }
  }
  return 0;
}
void add_phone(phone *&variety, int &size)
{
  string name;
  string company;
  int index;
  cout << "enter mobile name" << '\n';
  cin >> name;
  cout << "enter company name" << '\n';
  cin >> company;
  index = search(name, company, variety, size);
  if (index == -1)
  {
    reallocate(variety, size);
    variety[size - 1].name = name;
    variety[size - 1].company = company;
    cout << "enter price" << '\n';
    cin >> variety[size - 1].price;
    cout << "how many phone do you want to add?" << '\n';
    cin >> variety[size - 1].exist;
    get_OS(variety, size);
    get_color(variety, size);
    get_ram(variety, size);
    get_storage(variety, size);
  }
  else
  {
    int number = 0;
    cout << "how many phone do you want to add?" << '\n';
    cin >> number;
    variety[index].exist += number;
  }
}
void show(phone *variety, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << "mobile name :" << '\t';
    cout << variety[i].name << '\n';
    cout << "company name :" << '\t';
    cout << variety[i].company << '\n';
    cout << "price :" << '\t';
    cout << variety[i].price << '\n';
    cout << "number of mobile :" << '\t';
    cout << variety[i].exist << '\n';
    cout << "number of salled mobile :" << '\t';
    cout << variety[i].salled << '\n';
    cout << "OS:" << '\t';
    show_os(variety, i);
    cout << "Color:" << '\t';
    show_color(variety, i);
    cout << "ram:" << '\t';
    show_ram(variety, i);
    cout << "Storage:" << '\t';
    show_storage(variety, i);
  }
}
void reallocate(phone *&variety, int &size)
{
  phone *temp = new phone[size + 1];
  for (int i = 0; i < size; i++)
  {
    temp[i] = variety[i];
  }
  size++;
  delete[] variety;
  variety = temp;
}
void remove_phone(phone *&variety, int &size)
{
  string name;
  string company;
  int index = 0;
  cout << "enter name " << '\n';
  cin >> name;
  cout << "enter  company name" << '\n';
  cin >> company;
  index = search(name, company, variety, size);
  for (int i = 0; i < size; i++)
  {

    if (i == index)
    {

      for (int j = i; j < size - 1; j++)
        variety[j] = variety[j + 1];
      --size;
    }
  }
  if (index == -1)
  {
    cout << "Mobile not found" << '\n';
  }
}
int search(string name, string company, phone *variety, int size)
{
  int index = -1;
  for (int i = 0; i < size; i++)
  {
    if (variety[i].name == name && variety[i].company == company)
    {
      index = i;
    }
  }
  if (index > -1)
  {
    return index;
  }
  else
  {
    return -1;
  }
}
void search_phone(phone *variety, int size)
{
  string name;
  string company;
  int index = -1;
  cout << "enter mobile name" << '\n';
  cin >> name;
  cout << "enter company name" << '\n';
  cin >> company;
  for (int i = 0; i < size; i++)
  {
    if (variety[i].name == name && variety[i].company == company)
    {
      index = i;
    }
  }
  if (index > -1)
  {
    cout << "mobile name :" << '\t';
    cout << variety[index].name << '\n';
    cout << "company name :" << '\t';
    cout << variety[index].company << '\n';
    cout << "price :" << '\t';
    cout << variety[index].price << '\n';
    cout << "number of mobile :" << '\t';
    cout << variety[index].exist << '\n';
    cout << "number of salled mobile :" << '\t';
    cout << variety[index].salled << '\n';
    cout << "OS:" << '\t';
    show_os(variety, index);
    cout << "Color:" << '\t';
    show_color(variety, index);
    cout << "ram:" << '\t';
    show_ram(variety, index);
    cout << "Storage:" << '\t';
    show_storage(variety, index);
  }
  if (index == -1)
  {
    cout << "mobile not found" << '\n';
  }
}
void change_mobile_info(phone *&variety, int size)
{
  int answer = 0;
  do
  {
    cout << "1)change mobile name" << '\n';
    cout << "2)change mobile company" << '\n';
    cout << "3)change mobile price" << '\n';
    cout << "4)quite" << '\n';
    cin >> answer;
    switch (answer)
    {
    case 1:
      change_name(variety, size);
      break;
    case 2:
      change_company(variety, size);
      break;
    case 3:
      change_price(variety, size);
      break;
    default:
      break;
    }
  } while (answer != 4);
}
void change_name(phone *&variety, int size)
{
  string name;
  string newname;
  string company;
  int index = -1;
  cout << "enter mobile name" << '\n';
  cin >> name;
  cout << "enter company name" << '\n';
  cin >> company;
  cout << "enter mobile newname" << '\n';
  cin >> newname;
  for (int i = 0; i < size; i++)
  {
    if (variety[i].name == name && variety[i].company == company)
    {
      variety[i].name = newname;
      index = i;
    }
  }
  if (index == -1)
  {
    cout << "not found";
  }
}
void change_company(phone *&variety, int size)
{
  string name;
  string newcompany;
  string company;
  int index = -1;
  cout << "enter mobile name" << '\n';
  cin >> name;
  cout << "enter company name" << '\n';
  cin >> company;
  cout << "enter mobile new company" << '\n';
  cin >> newcompany;
  for (int i = 0; i < size; i++)
  {
    if (variety[i].name == name && variety[i].company == company)
    {
      index = i;
      variety[index].company = newcompany;
    }
  }
  if (index > 0)
  {
    cout << "not found";
  }
}
void change_price(phone *&variety, int size)
{
  string name;
  long long price;
  string company;
  int index = -1;
  cout << "enter mobile name" << '\n';
  cin >> name;
  cout << "enter company name" << '\n';
  cin >> company;
  cout << "enter mobile new price" << '\n';
  cin >> price;
  for (int i = 0; i < size; i++)
  {
    if (variety[i].name == name && variety[i].company == company)
    {
      index = i;
      variety[index].price = price;
    }
  }
  if (index == -1)
  {
    cout << "not found";
  }
}
void sell_a_phone(phone *&variety, int size)
{
  string name;
  string company;
  int index = -1;
  cout << "enter mobile name" << '\n';
  cin >> name;
  cout << "enter company name" << '\n';
  cin >> company;
  for (int i = 0; i < size; i++)
  {
    if (variety[i].name == name && variety[i].company == company)
    {
      index = i;
      variety[index].exist -= 1;
      variety[index].salled += 1;
    }
  }
  if (index == -1)
  {
    cout << "not found";
  }
}
void sort_by_price(phone *&variety, int size)
{
  phone temp;
  for (int i = 1; i < size; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (variety[i].price < variety[j].price)
      {
        temp = variety[i];
        variety[i] = variety[j];
        variety[j] = temp;
      }
    }
  }
  cout << "sort is successFully!" << '\n';
}
void most_sold_items(phone *variety, int size)
{
  phone temp;
  phone *array = new phone[size];
  for (int i = 0; i < size; i++)
  {
    array[i] = variety[i];
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (array[i].salled < array[j].salled)
      {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
  show(array, size);
  delete[] array;
}
void get_OS(phone *&variety, int size)
{
  int flag = -1;
  cout << "choose number :" << '\n';
  cout << "iOS = 0" << '\n';
  cout << "Android = 1" << '\n';
  cout << "windowsphone = 2" << '\n';
  cin >> flag;
  if (flag == 0)
  {
    variety[size - 1].type = OS::iOS;
  }
  if (flag == 1)
  {
    variety[size - 1].type = OS::Android;
  }
  if (flag == 2)
  {
    variety[size - 1].type = OS::windowsphone;
  }
}
void get_color(phone *&variety, int size)
{
  int flag = -1;
  cout << "choose number :" << '\n';
  cout << "black=0" << '\n';
  cout << "white=1" << '\n';
  cout << "blue=2" << '\n';
  cout << "pink=3" << '\n';
  cin >> flag;
  if (flag == 0)
  {
    variety[size - 1].color = Color::black;
  }
  if (flag == 1)
  {
    variety[size - 1].color = Color::white;
  }
  if (flag == 2)
  {
    variety[size - 1].color = Color::blue;
  }
  if (flag == 3)
  {
    variety[size - 1].color = Color::pink;
  }
}
void get_ram(phone *&variety, int size)
{
  int flag = -1;
  cout << "choose number ram:" << '\n';
  cout << "twoGB = 0" << '\n';
  cout << "fourGB=1" << '\n';
  cout << "sixGB=2" << '\n';
  cout << "twelveGB=3 " << '\n';
  cout << "sixteenGB=4 " << '\n';
  cout << "thirtytwoGB=5 " << '\n';
  cout << "fourtytwoGB=6" << '\n';
  cin >> flag;
  if (flag == 0)
  {
    variety[size - 1].ram = Ram::twoGB;
  }
  if (flag == 1)
  {
    variety[size - 1].ram = Ram::fourGB;
  }
  if (flag == 2)
  {
    variety[size - 1].ram = Ram::sixGB;
  }
  if (flag == 3)
  {
    variety[size - 1].ram = Ram::twelveGB;
  }
  if (flag == 4)
  {
    variety[size - 1].ram = Ram::sixteenGB;
  }
  if (flag == 5)
  {
    variety[size - 1].ram = Ram::thirtytwoGB;
  }
  if (flag == 6)
  {
    variety[size - 1].ram = Ram::fourtytwoGB;
  }
}
void get_storage(phone *&variety, int size)
{
  int flag = -1;
  cout << "choose number storage :" << '\n';
  cout << "sixteenGB = 0" << '\n';
  cout << "thirtytwoGB=1" << '\n';
  cout << "fourtytwoGB=2" << '\n';
  cout << "onetwoeightGB,=3 " << '\n';
  cout << "twofivesixGB=4 " << '\n';
  cout << "fiveonetwoGB=5 " << '\n';
  cout << "oneTB =6" << '\n';
  cout << "twoTB=7" << '\n';
  cin >> flag;
  if (flag == 0)
  {
    variety[size - 1].storage = Storage::sixtenGB;
  }
  if (flag == 1)
  {
    variety[size - 1].storage = Storage::thirtitwoGB;
  }
  if (flag == 2)
  {
    variety[size - 1].storage = Storage::fourtitwoGB;
  }
  if (flag == 3)
  {
    variety[size - 1].storage = Storage::onetwoeightGB;
  }
  if (flag == 4)
  {
    variety[size - 1].storage = Storage::twofivesixGB;
  }
  if (flag == 5)
  {
    variety[size - 1].storage = Storage::fiveonetwoGB;
  }
  if (flag == 6)
  {
    variety[size - 1].storage = Storage::oneTB;
  }
  if (flag == 7)
  {
    variety[size - 1].storage = Storage::twoTB;
  }
}
void show_os(phone *variety, int i)
{
  if (variety[i].type == 0)
  {
    cout << "iOS" << '\n';
  }
  if (variety[i].type == 1)
  {
    cout << "Android" << '\n';
  }
  if (variety[i].type == 2)
  {
    cout << "windowsphone" << '\n';
  }
}
void show_color(phone *variety, int i)
{
  if (variety[i].color == 0)
  {
    cout << "black" << '\n';
  }
  if (variety[i].color == 1)
  {
    cout << "white" << '\n';
  }
  if (variety[i].color == 2)
  {
    cout << "blue" << '\n';
  }
  if (variety[i].color == 3)
  {
    cout << "pink" << '\n';
  }
}
void show_ram(phone *variety, int i)
{
  if (variety[i].ram == 0)
  {
    cout << "twoGB" << '\n';
  }
  if (variety[i].ram == 1)
  {
    cout << "fourGB" << '\n';
  }
  if (variety[i].ram == 2)
  {
    cout << "sixGB" << '\n';
  }
  if (variety[i].ram == 3)
  {
    cout << "twelveGB" << '\n';
  }
  if (variety[i].ram == 4)
  {
    cout << "sixteenGB" << '\n';
  }
  if (variety[i].ram == 5)
  {
    cout << "thirtytwoGB" << '\n';
  }
  if (variety[i].ram == 6)
  {
    cout << "fourtytwoGB" << '\n';
  }
}
void show_storage(phone *variety, int i)
{
  if (variety[i].storage == 0)
  {
    cout << "sixtenGB" << '\n';
  }
  if (variety[i].storage == 1)
  {
    cout << "thirtitwoGB" << '\n';
  }
  if (variety[i].storage == 2)
  {
    cout << "fourtitwoGB" << '\n';
  }
  if (variety[i].storage == 3)
  {
    cout << "onetwoeightGB" << '\n';
  }
  if (variety[i].storage == 4)
  {
    cout << "twofivesixGB" << '\n';
  }
  if (variety[i].storage == 5)
  {
    cout << "fiveonetwoGB" << '\n';
  }
  if (variety[i].storage == 6)
  {
    cout << "oneTB" << '\n';
  }
  if (variety[i].storage == 7)
  {
    cout << "twoTB" << '\n';
  }
}
