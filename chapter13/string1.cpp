#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    string hello("hello");
    hello.replace(0, 4, "algorithm");   //hell => algorithm, algorithmo
    cout << "hello: " << hello << endl;


    string fileName, baseName, extName, tmpName;
    const string suffix("tmp");     //无.tmp =》.tmp, 否则=》.xxx

    //for each conmand-line argument
    for (int i = 1; i < argc; ++i){
        //process argument as filename
        fileName = argv[i];

        //search period in filename
        string::size_type idx = fileName.find('.');

        if (idx == string::npos) {
            //filename does not contain any period
            tmpName = fileName + '.' + suffix;
        }
        else {
            //split filename into base name and extension
            baseName = fileName.substr(0, idx);
            extName  = fileName.substr(idx+1);

            if (extName.empty()) {
                //contains period but no extension
                tmpName = fileName;
                tmpName += suffix;
            }
            else if (extName == suffix) {
                //replace extension tmp with xxx
                tmpName = fileName;
                tmpName.replace(idx+1, extName.size(), "xxx");
                //tmpName.replace(idx + 1, 2, "xxx");
            }
            else {
                //replace any extension with tmp
                tmpName = fileName;
                tmpName.replace(idx+1, string::npos, suffix);
            }
        }

        //print filename and temporary name
        cout << fileName << "=>" << tmpName << endl;

    }

    system("pause");
    return 0;
}
