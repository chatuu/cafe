// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main () {

        string line;
        string location;
        string file;
        string fullname;
        int i=0;

        ifstream myfile ("filelist.txt");
        if (myfile.is_open())
        {
                while ( getline (myfile,line) )
                {


                        if(!line.empty()) {

                                if(line.length()>11) {

                                        std::size_t pos = line.find(".");
                                        //std::string root = line.substr (pos);

                                        if(pos==0) {
                                                location=line;
//std::cout<<line<<std::endl;
                                        }
                                        else{
                                                file=line;
                                                i++;
                                                fullname=location+file;
                                                replace(fullname.begin(),fullname.end(),':','/');
                                                cout << fullname<<" "<<i << endl;

                                        }

                                }


                        }


                }
                myfile.close();
        }

        else cout << "Unable to open file"<<endl;

        return 0;
}
