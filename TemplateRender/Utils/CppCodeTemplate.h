#include<iostream>
using namespace std;


static const string programBegin = "#include <Windows.h>\n "
" #include <iostream>\n "
" #include <string>\n "
" #include <list> \n "
" #include <fstream>\n "
" #include \"..//Data//Data.h\" "
" #include <direct.h>\n "
" using namespace std;\n "
" int main()\n "
"{\n "
" _mkdir(\"Rendered_HTML_Page\");"
"\n std::ofstream file;\n"
" file.open(\"Rendered_HTML_Page//index.html\");\n"
" if (file.is_open())\n "
"{\n"
" auto Model = Data::object ;\n" ;



static const string programEnd = "}\n"
"file.close();\n"
"return 0;\n"
"}\n";