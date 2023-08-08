#include <bits/stdc++.h>
using namespace std;
int convert(string s)
{
    int num = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        num = num * 10 + (int(s[i]) - 48);
    }
    return num;
}
string toBin(int num, int bits=8)
{
    string str = "";
    while (num > 0)
    {
        int last = num % 2;
        str = to_string(last) + str;
        num = num / 2;
    }

    while (str.length() != bits)
    {
        str = '0' + str;
    }
    return str;
}
void convertBinary(vector<string> &parts)
{
    int size = 4;
    for (int i = 0; i < 4; i++)
    {
        string str = parts[i];
        int num = convert(str);
        parts[i] = toBin(num);
    }
}
void printClass(vector<string> ans, string str)
{
    if (ans[0][0] == '0')
    {
        cout << "IP Address: " << str << " is from Class A" << endl;
    }
    if (ans[0][0] == '1' && ans[0][1] == '0')
    {
        cout << "IP Address: " << str << " is from Class B" << endl;
    }

    if (ans[0][0] == '1' && ans[0][1] == '1' && ans[0][2] == '0')
    {
        cout << "IP Address: " << str << " is from Class C" << endl;
    }

    if (ans[0][0] == '1' && ans[0][1] == '1' && ans[0][2] == '1' && ans[0][3] == '0')
    {
        cout << "IP Address: " << str << " is from Class D" << endl;
    }

    if (ans[0][0] == '1' && ans[0][1] == '1' && ans[0][2] == '1' && ans[0][3] == '1' && ans[0][4] == '0')
    {
        cout << "IP Address: " << str << " is from Class E" << endl;
    }
}
int printSubnetVector(vector<int> ip_bin)
{
    int ft = 0;
    int sd = 0;
    int td = 0;
    int fh = 0;
    for (int i = 0; i < 8; i++)
    {
        ft = ft * 2 + ip_bin[i];
    }
    for (int i = 8; i < 16; i++)
    {
        sd = sd * 2 + ip_bin[i];
    }
    for (int i = 16; i < 24; i++)
    {
        td = td * 2 + ip_bin[i];
    }
    for (int i = 24; i < 32; i++)
    {
        fh = fh * 2 + ip_bin[i];
    }

    cout << ft << "." << sd << "." << td << "." << fh << endl;
    return fh;
}

void printSubAddHel(vector<int> ip_bin, int start, int end, string subnet, int i)
{
    vector<int> bits(32);
    for (int i = 0; i < 24; i++)
    {
        bits[i] = ip_bin[i];
    }
    for (int i = 24; i < 32; i++)
    {
        bits[i] = 0;
    }
    int subnetBits = subnet.length();
    for (int i = 0; i < subnetBits; i++)
    {
        bits[end + i] = (subnet[i] - '0');
    }
    cout << "Starting IP Address of subnet " << i << " is: ";
    int ftUsuable = printSubnetVector(bits) + 1;
    for (int i = start + 1; i < 32; i++)
    {
        bits[i] = 1;
    }
    cout << "Last IP Address of subnet " << i << " is: ";
    int LastUsuable = printSubnetVector(bits) - 1;

    int ft = 0;
    int sd = 0;
    int td = 0;
    for (int i = 0; i < 8; i++)
    {
        ft = ft * 2 + bits[i];
    }
    for (int i = 8; i < 16; i++)
    {
        sd = sd * 2 + bits[i];
    }
    for (int i = 16; i < 24; i++)
    {
        td = td * 2 + bits[i];
    }
    string ip = to_string(ft) + '.' + to_string(sd) + '.' + to_string(td) + '.';
    cout << "Usable IP Range in subnet 1: ";
    cout << ip + to_string(ftUsuable) << " to ";
    cout << ip + to_string(LastUsuable);
}

void printSubAdd(vector<int> ip_bin, int subnetBits)
{
    int subnetsPossible = pow(2, subnetBits);
    int startIndex = 23 + subnetBits;
    int endIndex = 24;
    for (int i = 0; i < subnetsPossible; i++)
    {
        string binarySubnet = toBin(i, subnetBits);
        if (i == 1)
        {
            printSubAddHel(ip_bin, startIndex, endIndex, binarySubnet, i);
            cout << endl<< endl;
        }
    }
}

void network(vector<int> ip_bin)
{
    int ft = 0;
    int sd = 0;
    int td = 0;
    for (int i = 0; i < 8; i++)
    {
        ft = ft * 2 + ip_bin[i];
    }
    for (int i = 8; i < 16; i++)
    {
        sd = sd * 2 + ip_bin[i];
    }
    for (int i = 16; i < 24; i++)
    {
        td = td * 2 + ip_bin[i];
    }
    cout << "Network Address: " << ft << "." << sd << "." << td << ".0" << endl;
}

void brodcast(vector<int> ip_bin)
{
    int ft = 0;
    int sd = 0;
    int td = 0;
    for (int i = 0; i < 8; i++)
    {
        ft = ft * 2 + ip_bin[i];
    }
    for (int i = 8; i < 16; i++)
    {
        sd = sd * 2 + ip_bin[i];
    }
    for (int i = 16; i < 24; i++)
    {
        td = td * 2 + ip_bin[i];
    }
    cout << "BroadCast Address: " << ft << "." << sd << "." << td << ".255" << endl;
}

int main()
{
    cout << "Enter the IP Address: ";
    string str;
    cin >> str;
    vector<string> parts(4);
    int index = 0;
    int prev = 0;
    bool isDecimal = false;
    int i;
    for (i = 0; i <= str.length(); i++)
    {
        if (str[i] == '.' || str[i] == '/')
        {
            string s = str.substr(prev, i - prev);
            if (s.length() != 8)
            {
                isDecimal = true;
            }
            parts[index] = s;
            index++;
            prev = i + 1;
        }
        if (str[i] == '/')
        {
            i++;
            break;
        }
    }
    int bits = 0;
    for (; i < str.length(); i++)
    {
        bits = bits * 10 + (str[i] - '0');
    }
    printClass(parts, str);
    if (isDecimal)
    {
        convertBinary(parts);
        cout << "The converted IP Address is: " << parts[0] << "." << parts[1] << "." << parts[2] << "." << parts[3] << endl;
    }

    vector<int> BinaryForm(32, 0);
    index = 0;
    for (int i = 0; i < 4; i++)
    {
        string s = parts[i];
        for (int j = 0; j < 8; j++)
        {
            BinaryForm[index] = (s[j] - '0');
            index++;
        }
    }
    brodcast(BinaryForm);
    network(BinaryForm);

    int subnetBits = bits - 24;
    cout << "Number of Subnets: " << pow(2, subnetBits) << endl;
    printSubAdd(BinaryForm, subnetBits);
    cout << "Ayush Sharma[21BDS0058]" << endl;

    return 0;
}
