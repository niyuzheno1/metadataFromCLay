#include <bits/stdc++.h>
using namespace std;
//generator for rt.json and wt.json
struct ReadWriteType {
    string Type;
    vector<string> dependencies;
    string getJSON(){
        string json = "{";
        json += "\"Type\":\"" + Type + "\",";
        json += "\"dependencies\":[";
        for(int i = 0; i < dependencies.size(); i++){
            json += "\"" + dependencies[i] + "\"";
            if(i != dependencies.size() - 1)
                json += ",";
        }
        json += "]}";
        return json;
    }
};

ReadWriteType rwt;

map<string, vector<string>> dp, dp2;

string curtype;
struct DoIt{
    void insert(string & x){
        dp[curtype].push_back(x);
    }
};

struct IFun{
    DoIt doit;
};

IFun ifun;


void getWriteType(string etype, string basestr){
     curtype = etype;
     if(etype=="int" || etype=="signed" || etype=="signed int"){
      if(basestr=="") ifun.doit.insert((string)"writer_int");
      else            ifun.doit.insert((string)"writer_int_withBase");
    } 
     else if(etype=="long long" || etype=="signed long long" || etype=="ll"){
          if(basestr=="") ifun.doit.insert((string)"writer_ll");
          else            ifun.doit.insert((string)"writer_ll_withBase");
        } else if(etype=="unsigned" || etype=="unsigned int" || etype=="uint"){
          ifun.doit.insert((string)"writer_unsigned");
        } else if(etype=="unsigned long long" || etype=="ull"){
          ifun.doit.insert((string)"writer_ull");
        } else if(etype=="int8_t" || etype=="int16_t" || etype=="int32_t" || etype=="int64_t" || etype=="__int8_t" || etype=="__int16_t" || etype=="__int32_t" || etype=="__int64_t" || etype=="__int128_t"){
          ifun.doit.insert((string)"writer_int");
          ifun.doit.insert((string)"writer_ll");
          ifun.doit.insert((string)"writer_int128");
        } else if(etype=="uint8_t" || etype=="uint16_t" || etype=="uint32_t" || etype=="uint64_t" || etype=="__uint8_t" || etype=="__uint16_t" || etype=="__uint32_t" || etype=="__uint64_t" || etype=="__uint128_t"){
          ifun.doit.insert((string)"writer_unsigned");
          ifun.doit.insert((string)"writer_ull");
          ifun.doit.insert((string)"writer_uint128");
        } else if(etype=="Modint"){
          ifun.doit.insert((string)"writer_Modint");
        } else if(etype=="Mint"){
          ifun.doit.insert((string)"writer_Mint");
        } else if(etype=="modint"){
          ifun.doit.insert((string)"writer_modint");
        } else if(etype=="mint"){
          ifun.doit.insert((string)"writer_mint");
        } else if(etype=="double"){
          ifun.doit.insert((string)"writer_double");
        } else if(etype=="char"){
          ifun.doit.insert((string)"writer_char_array");
        } else if(etype=="string"){
          ifun.doit.insert((string)"writer_string");
        } else {
          //fprintf(stderr, "unknown type [%s] for wt (writer) : %s\n", etype.c_str(), vtmp[k].c_str());
          //assert(0);
        }
}

void getReadType(string etype, string basestr){
    curtype = etype;
          if(etype=="int" || etype=="signed" || etype=="signed int"){
            ifun.doit.insert((string)"reader_int");
          } else if(etype=="long long" || etype=="signed long long" || etype=="ll"){
            ifun.doit.insert((string)"reader_ll");
          } else if(etype=="unsigned" || etype=="unsigned int" || etype=="uint"){
            ifun.doit.insert((string)"reader_unsigned");
          } else if(etype=="unsigned long long" || etype=="ull"){
            ifun.doit.insert((string)"reader_ull");
          } else if(etype=="int8_t" || etype=="int16_t" || etype=="int32_t" || etype=="int64_t" || etype=="__int8_t" || etype=="__int16_t" || etype=="__int32_t" || etype=="__int64_t" || etype=="__int128_t"){
            ifun.doit.insert((string)"reader_int");
            ifun.doit.insert((string)"reader_ll");
            ifun.doit.insert((string)"reader_int128");
          } else if(etype=="uint8_t" || etype=="uint16_t" || etype=="uint32_t" || etype=="uint64_t" || etype=="__uint8_t" || etype=="__uint16_t" || etype=="__uint32_t" || etype=="__uint64_t" || etype=="__uint128_t"){
            ifun.doit.insert((string)"reader_unsigned");
            ifun.doit.insert((string)"reader_ull");
            ifun.doit.insert((string)"reader_uint128");
          } else if(etype=="Modint"){
            ifun.doit.insert((string)"reader_Modint");
          } else if(etype=="Mint"){
            ifun.doit.insert((string)"reader_Mint");
          } else if(etype=="modint"){
            ifun.doit.insert((string)"reader_modint");
          } else if(etype=="mint"){
            ifun.doit.insert((string)"reader_mint");
          } else if(etype=="double"){
            ifun.doit.insert((string)"reader_double");
          } else if(etype=="char"){
            ifun.doit.insert((string)"reader_char");
            ifun.doit.insert((string)"reader_char_array");
          } else if(etype=="string"){
            ifun.doit.insert((string)"reader_string");
          } else {
           
          }
}

       
       
          
 
int main(){
    vector<string> primitiveTypes; 
    // if(flags["string"]) return "string";
    primitiveTypes.push_back("string");
    // if(flags["double"]) return "double";
    primitiveTypes.push_back("double");
    // if(flags["float"]) return "float";
    primitiveTypes.push_back("float");
    // if(flags["Modint"]) return "Modint";
    primitiveTypes.push_back("Modint");
    // if(flags["Mint"]) return "Mint";
    primitiveTypes.push_back("Mint");
    // if(flags["modint"]) return "modint";
    primitiveTypes.push_back("modint");
    // if(flags["mint"]) return "mint";
    primitiveTypes.push_back("mint");
    // if(flags["__uint128_t"]) return "__uint128_t";
    primitiveTypes.push_back("__uint128_t");
    // if(flags["__int128_t"]) return "__int128_t";
    primitiveTypes.push_back("__int128_t");
    // if(flags["unsigned long long"]) return "unsigned long long";
    primitiveTypes.push_back("unsigned long long");
    // if(flags["ull"]) return "unsigned long long";
    primitiveTypes.push_back("ull");
    // if(flags["long long"]) return "long long";
    primitiveTypes.push_back("long long");
    // if(flags["uint64_t"]) return "uint64_t";
    primitiveTypes.push_back("uint64_t");
    // if(flags["__uint64_t"]) return "__uint64_t";
    primitiveTypes.push_back("__uint64_t");
    // if(flags["int64_t"]) return "int64_t";
    primitiveTypes.push_back("int64_t");
    // if(flags["__int64_t"]) return "__int64_t";
    primitiveTypes.push_back("__int64_t");
    // if(flags["unsigned"]) return "unsigned";
    primitiveTypes.push_back("unsigned");
    // if(flags["unsigned int"]) return "unsigned";
    primitiveTypes.push_back("unsigned int");
    // if(flags["uint"]) return "unsigned";
    primitiveTypes.push_back("uint");
    // if(flags["int"]) return "int";
    primitiveTypes.push_back("int");
    // if(flags["signed int"]) return "int";
    primitiveTypes.push_back("signed int");
    // if(flags["signed"]) return "int";
    primitiveTypes.push_back("signed");
    // if(flags["uint32_t"]) return "uint32_t";
    primitiveTypes.push_back("uint32_t");
    // if(flags["__uint32_t"]) return "__uint32_t";
    primitiveTypes.push_back("__uint32_t");
    // if(flags["int32_t"]) return "int32_t";
    primitiveTypes.push_back("int32_t");
    // if(flags["__int32_t"]) return "__int32_t";
    primitiveTypes.push_back("__int32_t");
    // if(flags["uint16_t"]) return "uint16_t";
    primitiveTypes.push_back("uint16_t");
    // if(flags["__uint16_t"]) return "__uint16_t";
    primitiveTypes.push_back("__uint16_t");
    // if(flags["int16_t"]) return "int16_t";
    primitiveTypes.push_back("int16_t");
    // if(flags["__int16_t"]) return "__int16_t";
    primitiveTypes.push_back("__int16_t");
    // if(flags["char"]) return "char";
    primitiveTypes.push_back("char");
    // if(flags["uint8_t"]) return "uint8_t";
    primitiveTypes.push_back("uint8_t");
    // if(flags["__uint8_t"]) return "__uint8_t";
    primitiveTypes.push_back("__uint8_t");
    // if(flags["int8_t"]) return "int8_t";
    primitiveTypes.push_back("int8_t");
    // if(flags["__int8_t"]) return "__int8_t";
    primitiveTypes.push_back("__int8_t");
    
    primitiveTypes.push_back("void");
    
    vector<string> baseStr({"", "8"});
    for(int i = 0 ; i < primitiveTypes.size(); ++i){
        for(int j = 0 ; j < baseStr.size(); ++j){
            getWriteType(primitiveTypes[i] , baseStr[j]);
        }
    }
    swap(dp, dp2);
    for(int i = 0 ; i < primitiveTypes.size(); ++i){
        for(int j = 0 ; j < baseStr.size(); ++j){
            getReadType(primitiveTypes[i] , baseStr[j]);
        }
    }
    swap(dp, dp2);
    ofstream ofs("wt.json");
    for(pair<const string, vector<string>> & p : dp){
        ReadWriteType rw;
        rw.Type = p.first;
        rw.dependencies = p.second;
        ofs << rw.getJSON() <<"," << endl;

    }
    ofstream ofs2("rt.json");

     for(pair<const string, vector<string>> & p : dp2){
        ReadWriteType rw;
        rw.Type = p.first;
        rw.dependencies = p.second;
        ofs2 << rw.getJSON() <<"," << endl;

    }

    return 0;
}


//generator for generating required identities
#include <bits/stdc++.h>
using namespace std;


string writeArray(vector<string> & x){
    ostringstream fout;
    for(int i = 0; i < x.size(); ++i){
        string line =  x[i];
        string newline;
        newline = "";
        for(int i = 0; i < line.length(); ++i){
            switch(line[i]){
            case '\"':
                newline += "\\";
                newline += "\"";
                break;
            case '\\':
                newline += "\\\\";
                break;
            default:
                newline += line[i];
                break;
            }
        }
        line = newline;
        

        if(i == x.size()-1){
            fout << "\"" << line << "\"" << endl;
            break;
        }
        fout << "\"" << line << "\"" << "," << endl;
    }
    return fout.str();
};

struct IFunction{
    string name;
    int argc; 
    int subargc;
    string alias = "";
    string condition;
    vector<string> dependencies;
    string getJSON(){
        string json = "{";
        json += "\"name\":\"" + name + "\",";
        json += "\"argc\":" + to_string(argc) + ",";
        json += "\"alias\":\"" + alias + "\",";
        json += "\"condition\":\"" + condition + "\",";
        json += "\"dependencies\":[" + writeArray(dependencies) + "],";
        json += "\"subargc\":" + to_string(subargc) + "";
        json += "}";
        return json;
    }
    IFunction(){
        name = "";
        argc = 0;
        condition = "";
        dependencies = {};
        subargc = 0;
    }
};
IFunction curFun;


struct DoIt{
    void insert(string & x){
        curFun.dependencies.push_back(x);
    }
};

struct IFun{
    DoIt doit;
};

IFun ifun;

ofstream fout("a.json");

void findFunction(string dummy, string X){
    //scan X for function name
    fout << curFun.getJSON() <<"," << endl;
    curFun = IFunction();
    string name = "";
    for(int i = 0; i < X.length(); ++i){
        if(X[i] == '(' || X[i] == '<'){
            break;
        }
        name += X[i];
    }
    curFun.name = name;
    curFun.condition = name;
}

struct VSSize{
    bool operator==(int x){
        if(curFun.argc != 0){
          fout << curFun.getJSON() <<"," << endl;
        }
        curFun.dependencies.clear();
        curFun.argc = x;
        return true;
    }
};

struct VS{
    VSSize x;
    VSSize size(){
        return x;
    }
    string operator[](int x){
      return "";
    }
};

struct VSSSize{
    bool operator==(int x){
        if(curFun.argc != 0){
          fout << curFun.getJSON() <<"," << endl;
        }
        curFun.dependencies.clear();
        curFun.subargc = x;
        return true;
    }
};

struct VSS{
  VSSSize x;
  VSSSize size(){
    return x;
  }
  
};

VS vs;

void alias(string x){
    //split before parethese
    string alias = "";
    for(int i = 0; i < x.length(); ++i){
        if(x[i] == '('){
            break;
        }
        alias += x[i];
    }
    curFun.alias = alias;
}
VSS vss;
VSS split_p(string x, char y){
  return vss; 
}

void test(){
    string tmp = "dummy";
    VSS vtmp;
    #define continue alias(tmp)
    findFunction(tmp, "rdLine()");
    if(vs.size() == 3){
      ifun.doit.insert((string)"rdLine");
      tmp = vs[0] + "rdLine_L(" + vs[1] + ")" + vs[2];
      continue;
    }
     findFunction(tmp, "sortA()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size()==2) ifun.doit.insert((string)"sortA_1");
        if(vtmp.size()==3) ifun.doit.insert((string)"sortA_1"), ifun.doit.insert((string)"sortA_2");
        if(vtmp.size()==4) ifun.doit.insert((string)"sortA_2"), ifun.doit.insert((string)"sortA_3");
        if(vtmp.size()==5) ifun.doit.insert((string)"sortA_3"), ifun.doit.insert((string)"sortA_4");
        tmp = vs[0] + "sortA_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "sortA_index()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size()==3) ifun.doit.insert((string)"sortA_index_2");
        if(vtmp.size()==4) ifun.doit.insert((string)"sortA_index_2"), ifun.doit.insert((string)"sortA_index_3");
        if(vtmp.size()==5) ifun.doit.insert((string)"sortA_index_3"), ifun.doit.insert((string)"sortA_index_4");
        tmp = vs[0] + "sortA_index_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "rsortA()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size()==2) ifun.doit.insert((string)"rsortA_1");
        if(vtmp.size()==3) ifun.doit.insert((string)"rsortA_1"), ifun.doit.insert((string)"rsortA_2");
        if(vtmp.size()==4) ifun.doit.insert((string)"rsortA_2"), ifun.doit.insert((string)"rsortA_3");
        if(vtmp.size()==5) ifun.doit.insert((string)"rsortA_3"), ifun.doit.insert((string)"rsortA_4");
        tmp = vs[0] + "rsortA_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "sortV()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size()==1) ifun.doit.insert((string)"sortV_1");
        if(vtmp.size()==2) ifun.doit.insert((string)"sortV_1"), ifun.doit.insert((string)"sortV_2");
        if(vtmp.size()==3) ifun.doit.insert((string)"sortV_2"), ifun.doit.insert((string)"sortV_3");
        if(vtmp.size()==4) ifun.doit.insert((string)"sortV_3"), ifun.doit.insert((string)"sortV_4");
        tmp = vs[0] + "sortV_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "rsortV()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size()==1) ifun.doit.insert((string)"rsortV_1");
        if(vtmp.size()==2) ifun.doit.insert((string)"rsortV_1"), ifun.doit.insert((string)"rsortV_2");
        if(vtmp.size()==3) ifun.doit.insert((string)"rsortV_2"), ifun.doit.insert((string)"rsortV_3");
        if(vtmp.size()==4) ifun.doit.insert((string)"rsortV_3"), ifun.doit.insert((string)"rsortV_4");
        tmp = vs[0] + "rsortV_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "sortF()");
      if(vs.size() == 3){ // 手抜き
        vtmp = split_p(vs[1], ',');
        ifun.doit.insert((string)"sortF_int");
        ifun.doit.insert((string)"sortF_ll");
        tmp = vs[0] + "sortF_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    

    findFunction(tmp, "Digit()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 1) ifun.doit.insert((string)"Digit");
        if(vtmp.size() == 2) ifun.doit.insert((string)"Digit_base");
        if(vtmp.size() == 2) ifun.doit.insert((string)"Digit_all");
        if(vtmp.size() == 3) ifun.doit.insert((string)"Digit_all_base");
        tmp = vs[0] + "Digit_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "DigitF()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 3) ifun.doit.insert((string)"DigitF_all");
        if(vtmp.size() == 4) ifun.doit.insert((string)"DigitF_all_base");
        tmp = vs[0] + "DigitF_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "invDigit()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 2) ifun.doit.insert((string)"invDigit");
        if(vtmp.size() == 3) ifun.doit.insert((string)"invDigit_base");
        tmp = vs[0] + "invDigit_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "sod()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 1) ifun.doit.insert((string)"sod");
        if(vtmp.size() == 2) ifun.doit.insert((string)"sod_base");
        tmp = vs[0] + "sod_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "wAdjEdge()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 6 || vtmp.size() == 7) ifun.doit.insert((string)"wAdjEdge1");
        else if(vtmp.size() == 8 || vtmp.size() == 9) ifun.doit.insert((string)"wAdjEdge2");
        else if(vtmp.size() == 10 || vtmp.size() == 11) ifun.doit.insert((string)"wAdjEdge3");
        else if(vtmp.size() == 12 || vtmp.size() == 13) ifun.doit.insert((string)"wAdjEdge4");
        else{
          fprintf(stderr, "#arg of wAdjEdge is invalid\n");
          assert(0);
        }
        tmp = vs[0] + "wAdjEdge_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "convolution()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"convolution");
        ifun.doit.insert((string)"convolution-mint");
        ifun.doit.insert((string)"convolution-Mint");
        ifun.doit.insert((string)"convolution-modint");
        ifun.doit.insert((string)"convolution-Modint");
        tmp = vs[0] + "convolution_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "ZetaTransform()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"ZetaTransform");
        tmp = vs[0] + "ZetaTransform_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "ZetaTransform_min()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 2 || vtmp.size() == 3) ifun.doit.insert((string)"ZetaTransform_min");
        if(vtmp.size() == 4) ifun.doit.insert((string)"ZetaTransform_min2");
        if(vtmp.size() == 5) ifun.doit.insert((string)"ZetaTransform_min3");
        tmp = vs[0] + "ZetaTransform_min_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "ZetaTransform_max()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"ZetaTransform_max");
        tmp = vs[0] + "ZetaTransform_max_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "polationPoly()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"polationPoly");
        tmp = vs[0] + "polationPoly_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "Explode()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Explode");
        tmp = vs[0] + "Explode_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "Implode()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Implode");
        tmp = vs[0] + "Implode_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "InnerProd()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 2) ifun.doit.insert((string)"InnerProd_1");
        if(vtmp.size() == 3) ifun.doit.insert((string)"InnerProd_2");
        if(vtmp.size() == 4) ifun.doit.insert((string)"InnerProd_3");
        if(vtmp.size() == 5) ifun.doit.insert((string)"InnerProd_4");
        tmp = vs[0] + "InnerProd_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "crossProd()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"crossProd");
        tmp = vs[0] + "crossProd_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "LineIntersection_size()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"LineIntersection_size");
        tmp = vs[0] + "LineIntersection_size_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "arrEraseVal()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 3) ifun.doit.insert((string)"arrEraseVal1");
        if(vtmp.size() == 4) ifun.doit.insert((string)"arrEraseVal2");
        if(vtmp.size() == 5) ifun.doit.insert((string)"arrEraseVal3");
        if(vtmp.size() == 6) ifun.doit.insert((string)"arrEraseVal4");
        tmp = vs[0] + "arrEraseVal_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "vecEraseVal()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 2) ifun.doit.insert((string)"vecEraseVal1");
        tmp = vs[0] + "vecEraseVal_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "DistinctE()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 2) ifun.doit.insert((string)"DistinctE_2");
        if(vtmp.size() == 3) ifun.doit.insert((string)"DistinctE_3");
        if(vtmp.size() == 4) ifun.doit.insert((string)"DistinctE_4");
        tmp = vs[0] + "DistinctE_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "Mex()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 1) ifun.doit.insert((string)"Mex1");
        if(vtmp.size() == 2) ifun.doit.insert((string)"Mex2"), ifun.doit.insert((string)"Mex");
        if(vtmp.size() == 3) ifun.doit.insert((string)"Mex3"), ifun.doit.insert((string)"Mex");
        if(vtmp.size() == 4) ifun.doit.insert((string)"Mex");
        tmp = vs[0] + "Mex_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "Kth0()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 2) ifun.doit.insert((string)"Kth0_size2");
        if(vtmp.size() == 3) ifun.doit.insert((string)"Kth0_size3");
        if(vtmp.size() == 4) ifun.doit.insert((string)"Kth0_size4");
        tmp = vs[0] + "Kth0_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "Kth1()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 2) ifun.doit.insert((string)"Kth1_size2");
        if(vtmp.size() == 3) ifun.doit.insert((string)"Kth1_size3");
        if(vtmp.size() == 4) ifun.doit.insert((string)"Kth1_size4");
        tmp = vs[0] + "Kth1_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "Kth2()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 3) ifun.doit.insert((string)"Kth2_size3");
        if(vtmp.size() == 4) ifun.doit.insert((string)"Kth2_size4");
        tmp = vs[0] + "Kth2_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "Kth3()");
      if(vs.size() == 3){
        vtmp = split_p(vs[1], ',');
        if(vtmp.size() == 4) ifun.doit.insert((string)"Kth3_size4");
        tmp = vs[0] + "Kth3_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "KthA()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"KthA");
        tmp = vs[0] + "KthA_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "strReplace()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"strReplace1");
        ifun.doit.insert((string)"strReplace2");
        tmp = vs[0] + "strReplace_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "BIT_popcount()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"BIT_popcount");
        tmp = vs[0] + "BIT_popcount_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
    findFunction(tmp, "BIT_ctz()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"BIT_ctz");
        tmp = vs[0] + "BIT_ctz_L(" + vs[1] + ")" + vs[2];
        continue;
      }
      
   

    findFunction(tmp, "BIT_lowest()");
      if(vs.size() == 3){
        tmp = vs[0] + "(-(" + vs[1] + ") & (" + vs[1] + "))" + vs[2];
        continue;
      }

    findFunction(tmp, "BIT_nonlowest()");
      if(vs.size() == 3){
        tmp = vs[0] + "((" + vs[1] + ") & ((" + vs[1] + ")-1))" + vs[2];
        continue;
      }

    findFunction(tmp, "Prime()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Prime");
        tmp = vs[0] + "Prime_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Isqrt_f()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Isqrt_f");
        tmp = vs[0] + "Isqrt_f_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Isqrt_c()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Isqrt_c");
        tmp = vs[0] + "Isqrt_c_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Isqrt_s()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Isqrt_s");
        tmp = vs[0] + "Isqrt_s_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Icbrt_f()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Icbrt_f");
        tmp = vs[0] + "Icbrt_f_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Icbrt_c()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Icbrt_c");
        tmp = vs[0] + "Icbrt_c_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Icbrt_s()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Icbrt_s");
        tmp = vs[0] + "Icbrt_s_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Iroot_f()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Iroot_f");
        tmp = vs[0] + "Iroot_f_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Iroot_c()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Iroot_c");
        tmp = vs[0] + "Iroot_c_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Iroot_s()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Iroot_s");
        tmp = vs[0] + "Iroot_s_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Ilog2_f()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Ilog2_f");
        tmp = vs[0] + "Ilog2_f_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Ilog2_c()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Ilog2_c");
        tmp = vs[0] + "Ilog2_c_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Ilog2_s()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Ilog2_s");
        tmp = vs[0] + "Ilog2_s_L(" + vs[1] + ")" + vs[2];
        continue;
      }


    findFunction(tmp, "Isqrt()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Isqrt_f");
        tmp = vs[0] + "Isqrt_f_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Icbrt()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Icbrt_f");
        tmp = vs[0] + "Icbrt_f_L(" + vs[1] + ")" + vs[2];
        continue;
      }

    findFunction(tmp, "Iroot()");
      if(vs.size() == 3){
        ifun.doit.insert((string)"Iroot_f");
        tmp = vs[0] + "Iroot_f_L(" + vs[1] + ")" + vs[2];
        continue;
      }
    #undef continue

        findFunction(tmp, "primitiveRoot()");
      if(vs.size() == 3) ifun.doit.insert((string)"primitiveRoot");
      
    findFunction(tmp, "knightDistance()");
      if(vs.size() == 3) ifun.doit.insert((string)"knightDistance");
      
    findFunction(tmp, "LIS_length()");
      if(vs.size() == 3) ifun.doit.insert((string)"LIS_length");
      
    findFunction(tmp, "weaklyLIS_length()");
      if(vs.size() == 3) ifun.doit.insert((string)"weaklyLIS_length");
      
    findFunction(tmp, "LIS_ends()");
      if(vs.size() == 3) ifun.doit.insert((string)"LIS_ends");
      
    findFunction(tmp, "weaklyLIS_ends()");
      if(vs.size() == 3) ifun.doit.insert((string)"weaklyLIS_ends");
      
    findFunction(tmp, "longestSuffixPrefix()");
      if(vs.size() == 3) ifun.doit.insert((string)"longestSuffixPrefix");
      
    findFunction(tmp, "SuffixArray()");
      if(vs.size() == 3) ifun.doit.insert((string)"SuffixArray");
      
    findFunction(tmp, "smallestSubsequenceLengthK()");
      if(vs.size() == 3) ifun.doit.insert((string)"smallestSubsequenceLengthK");
      
    findFunction(tmp, "isSubstring()");
      if(vs.size() == 3) ifun.doit.insert((string)"isSubstring_string");
      
    findFunction(tmp, "isPalindrome()");
      if(vs.size() == 3) ifun.doit.insert((string)"isPalindrome");
      
    findFunction(tmp, "rd_int()");
      if(vs.size() == 3) ifun.doit.insert((string)"rd_int");
      
    findFunction(tmp, "rd_ll()");
      if(vs.size() == 3) ifun.doit.insert((string)"rd_ll");
      
    findFunction(tmp, "rd_string()");
      if(vs.size() == 3) ifun.doit.insert((string)"rd_string");
      
    findFunction(tmp, "fDiv()");
      if(vs.size() == 3) ifun.doit.insert((string)"fDiv");
      
    findFunction(tmp, "cDiv()");
      if(vs.size() == 3) ifun.doit.insert((string)"cDiv");
      
    findFunction(tmp, "floor_sum()");
      if(vs.size() == 3) ifun.doit.insert((string)"floor_sum");
      
    findFunction(tmp, "floor_sum2()");
      if(vs.size() == 3) ifun.doit.insert((string)"floor_sum2");
      
    findFunction(tmp, "graph_minColor()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_minColor");
      
    findFunction(tmp, "xorMin()");
      if(vs.size() == 3) ifun.doit.insert((string)"xorMin");
    findFunction(tmp, "xorMax()");
      if(vs.size() == 3) ifun.doit.insert((string)"xorMax");
      
    findFunction(tmp, "calcRollingHash()");
      if(vs.size() == 3) ifun.doit.insert((string)"rollingHash");
      
    findFunction(tmp, "fft()");
      if(vs.size() == 3) ifun.doit.insert((string)"fft");
      if(vs.size() == 3) ifun.doit.insert((string)"fft-mint");
      if(vs.size() == 3) ifun.doit.insert((string)"fft-Mint");
      if(vs.size() == 3) ifun.doit.insert((string)"fft-modint");
      if(vs.size() == 3) ifun.doit.insert((string)"fft-Modint");
      
    findFunction(tmp, "get_inv_mod()");
      if(vs.size() == 3) ifun.doit.insert((string)"get_inv_mod");
      
    findFunction(tmp, "extendedEuclid()");
      if(vs.size() == 3) ifun.doit.insert((string)"extendedEuclid");
      
    findFunction(tmp, "chineseRemainder()");
      if(vs.size() == 3) ifun.doit.insert((string)"chineseRemainder");
      
    findFunction(tmp, "writerDigit_double()");
      if(vs.size() == 3) ifun.doit.insert((string)"writer_double");
      
    findFunction(tmp, "arrcmp()");
      if(vs.size() == 3) ifun.doit.insert((string)"arrcmp");
      
    findFunction(tmp, "arrRot()");
      if(vs.size() == 3) ifun.doit.insert((string)"arrRot");
      
    findFunction(tmp, "Distinct()");
      if(vs.size() == 3) ifun.doit.insert((string)"Distinct");
      
    findFunction(tmp, "arrInsert()");
      if(vs.size() == 3) ifun.doit.insert((string)"arrInsert");
      
    findFunction(tmp, "reduceFraction()");
      if(vs.size() == 3) ifun.doit.insert((string)"reduceFraction");

    findFunction(tmp, "MoebiusTransform()");
      if(vs.size() == 3) ifun.doit.insert((string)"MoebiusTransform");

    findFunction(tmp, "isVowel()");
      if(vs.size() == 3) ifun.doit.insert((string)"isVowel");

    findFunction(tmp, "KMP()");
      if(vs.size() == 3) ifun.doit.insert((string)"KMP");

    findFunction(tmp, "Hungarian()");
      if(vs.size() == 3) ifun.doit.insert((string)"Hungarian");

    findFunction(tmp, "counterSumIsLT()");
      if(vs.size() == 3) ifun.doit.insert((string)"counterSumIsLT");

    findFunction(tmp, "counterProdIsLT()");
      if(vs.size() == 3) ifun.doit.insert((string)"counterProdIsLT");

    findFunction(tmp, "counterD2SumIsLT()");
      if(vs.size() == 3) ifun.doit.insert((string)"counterD2SumIsLT");

    findFunction(tmp, "counterM2SumIsLT()");
      if(vs.size() == 3) ifun.doit.insert((string)"counterM2SumIsLT");

    findFunction(tmp, "counterD2ProdIsLT()");
      if(vs.size() == 3) ifun.doit.insert((string)"counterD2ProdIsLT");

    findFunction(tmp, "counterM2ProdIsLT()");
      if(vs.size() == 3) ifun.doit.insert((string)"counterM2ProdIsLT");

    findFunction(tmp, "HammingDistance()");
      if(vs.size() == 3) ifun.doit.insert((string)"HammingDistance");

    findFunction(tmp, "editDistance()");
      if(vs.size() == 3) ifun.doit.insert((string)"editDistance");

    findFunction(tmp, "Cmod2()");
      if(vs.size() == 3) ifun.doit.insert((string)"Cmod2");

    findFunction(tmp, "next_mcomb()");
      if(vs.size() == 3) ifun.doit.insert((string)"next_mcomb");

    findFunction(tmp, "next_scomb()");
      if(vs.size() == 3) ifun.doit.insert((string)"next_scomb");

    findFunction(tmp, "next_marr()");
      if(vs.size() == 3) ifun.doit.insert((string)"next_marr");

    findFunction(tmp, "next_sarr()");
      if(vs.size() == 3) ifun.doit.insert((string)"next_sarr");

    findFunction(tmp, "next_sarr_s()");
      if(vs.size() == 3) ifun.doit.insert((string)"next_sarr_s");

    findFunction(tmp, "walloc1d()");
      if(vs.size() == 3) ifun.doit.insert((string)"walloc1d");

    findFunction(tmp, "walloc2d()");
      if(vs.size() == 3) ifun.doit.insert((string)"walloc2d");

    findFunction(tmp, "malloc1d()");
      if(vs.size() == 3) ifun.doit.insert((string)"malloc1d");

    findFunction(tmp, "free1d()");
      if(vs.size() == 3) ifun.doit.insert((string)"free1d");

    findFunction(tmp, "malloc2d()");
      if(vs.size() == 3) ifun.doit.insert((string)"malloc2d");

    findFunction(tmp, "free2d()");
      if(vs.size() == 3) ifun.doit.insert((string)"free2d");

    findFunction(tmp, "isPrime()");
      if(vs.size() == 3) ifun.doit.insert((string)"isPrime");

    findFunction(tmp, "Factor()");
      if(vs.size() == 3) ifun.doit.insert((string)"Factor");

    findFunction(tmp, "FactorM()");
      if(vs.size() == 3) ifun.doit.insert((string)"FactorM");

    findFunction(tmp, "Divisor()");
      if(vs.size() == 3) ifun.doit.insert((string)"Divisor");

    findFunction(tmp, "DivisorSum()");
      if(vs.size() == 3) ifun.doit.insert((string)"DivisorSum");

    findFunction(tmp, "Moebius()");
      if(vs.size() == 3) ifun.doit.insert((string)"Moebius");

    findFunction(tmp, "EulerPhi()");
      if(vs.size() == 3) ifun.doit.insert((string)"EulerPhi");

    findFunction(tmp, "BIT_parity()");
      if(vs.size() == 3) ifun.doit.insert((string)"BIT_parity");

    findFunction(tmp, "BIT_parity_pm()");
      if(vs.size() == 3) ifun.doit.insert((string)"BIT_parity_pm");

    findFunction(tmp, "prodDigits()");
      if(vs.size() == 3) ifun.doit.insert((string)"prodDigits");

    findFunction(tmp, "DigitHist()");
      if(vs.size() == 3) ifun.doit.insert((string)"DigitHist");

    findFunction(tmp, "invDigit_r()");
      if(vs.size() == 3) ifun.doit.insert((string)"invDigit_r");

    findFunction(tmp, "STR2int()");
      if(vs.size() == 3) ifun.doit.insert((string)"STR2int");

    findFunction(tmp, "STR2ll()");
      if(vs.size() == 3) ifun.doit.insert((string)"STR2ll");

    findFunction(tmp, "intervalSieve()");
      if(vs.size() == 3) ifun.doit.insert((string)"intervalSieve");

    findFunction(tmp, "powmod()");
      if(vs.size() == 3) ifun.doit.insert((string)"powmod");

    findFunction(tmp, "PowMod()");
      if(vs.size() == 3) ifun.doit.insert((string)"PowMod");

    findFunction(tmp, "runLength()");
      if(vs.size() == 3) ifun.doit.insert((string)"runLength");

    findFunction(tmp, "arrErase()");
      if(vs.size() == 3) ifun.doit.insert((string)"arrErase");

    findFunction(tmp, "arrCountVal()");
      if(vs.size() == 3) ifun.doit.insert((string)"arrCountVal");

    findFunction(tmp, "arrCountValSeqMax()");
      if(vs.size() == 3) ifun.doit.insert((string)"arrCountValSeqMax");

    findFunction(tmp, "RoundUp()");
      if(vs.size() == 3) ifun.doit.insert((string)"RoundUp");

    findFunction(tmp, "RoundDown()");
      if(vs.size() == 3) ifun.doit.insert((string)"RoundDown");

    findFunction(tmp, "Unique()");
      if(vs.size() == 3) ifun.doit.insert((string)"Unique");

    findFunction(tmp, "isSubsequence()");
      if(vs.size() == 3) ifun.doit.insert((string)"isSubsequence");

    findFunction(tmp, "isSubsequence_r()");
      if(vs.size() == 3) ifun.doit.insert((string)"isSubsequence_r");

    findFunction(tmp, "inversion_range()");
      if(vs.size() == 3) ifun.doit.insert((string)"inversion_range");

    findFunction(tmp, "inversion()");
      if(vs.size() == 3) ifun.doit.insert((string)"inversion");

    findFunction(tmp, "ZetaTransform2()");
      if(vs.size() == 3) ifun.doit.insert((string)"ZetaTransform2");

    findFunction(tmp, "MoebiusTransform2()");
      if(vs.size() == 3) ifun.doit.insert((string)"MoebiusTransform2");

    findFunction(tmp, "HadamardTransform()");
      if(vs.size() == 3) ifun.doit.insert((string)"HadamardTransform");

    findFunction(tmp, "xorConvolution()");
      if(vs.size() == 3) ifun.doit.insert((string)"xorConvolution");

    findFunction(tmp, "orConvolution()");
      if(vs.size() == 3) ifun.doit.insert((string)"orConvolution");

    findFunction(tmp, "andConvolution()");
      if(vs.size() == 3) ifun.doit.insert((string)"andConvolution");

    findFunction(tmp, "slideMin()");
      if(vs.size() == 3) ifun.doit.insert((string)"slideMin");

    findFunction(tmp, "slideMax()");
      if(vs.size() == 3) ifun.doit.insert((string)"slideMax");

    findFunction(tmp, "isLeapYear()");
      if(vs.size() == 3) ifun.doit.insert((string)"isLeapYear");

    findFunction(tmp, "dayOfWeek()");
      if(vs.size() == 3) ifun.doit.insert((string)"dayOfWeek");

    findFunction(tmp, "dayOfWeekStr()");
      if(vs.size() == 3) ifun.doit.insert((string)"dayOfWeekStr");

    findFunction(tmp, "prevDay()");
      if(vs.size() == 3) ifun.doit.insert((string)"prevDay");

    findFunction(tmp, "nextDay()");
      if(vs.size() == 3) ifun.doit.insert((string)"nextDay");

    findFunction(tmp, "dayIndex()");
      if(vs.size() == 3) ifun.doit.insert((string)"dayIndex");

    findFunction(tmp, "dayFromIndex()");
      if(vs.size() == 3) ifun.doit.insert((string)"dayFromIndex");

    findFunction(tmp, "polationVal()");
      if(vs.size() == 3) ifun.doit.insert((string)"polationVal");

    findFunction(tmp, "TSP_cycle()");
      if(vs.size() == 3) ifun.doit.insert((string)"TSP_cycle");

    findFunction(tmp, "TSP_path()");
      if(vs.size() == 3) ifun.doit.insert((string)"TSP_path");

    findFunction(tmp, "TSP_path_s()");
      if(vs.size() == 3) ifun.doit.insert((string)"TSP_path_s");

    findFunction(tmp, "maxSubsetDP()");
      if(vs.size() == 3) ifun.doit.insert((string)"maxSubsetDP");

    findFunction(tmp, "maxRectArea()");
      if(vs.size() == 3) ifun.doit.insert((string)"maxRectArea");

    findFunction(tmp, "isValidBracket1()");
      if(vs.size() == 3) ifun.doit.insert((string)"isValidBracket1");

    findFunction(tmp, "isValidBracket2()");
      if(vs.size() == 3) ifun.doit.insert((string)"isValidBracket2");

    findFunction(tmp, "swapV()");
      if(vs.size() == 3) ifun.doit.insert((string)"swapV");

    findFunction(tmp, "cntSubarrayFreq()");
      if(vs.size() == 3) ifun.doit.insert((string)"cntSubarrayFreq");

    findFunction(tmp, "cntSubarrayDistinct()");
      if(vs.size() == 3) ifun.doit.insert((string)"cntSubarrayDistinct");

    findFunction(tmp, "maxSubarrayDistinct()");
      if(vs.size() == 3) ifun.doit.insert((string)"maxSubarrayDistinct");

    findFunction(tmp, "vec2arr()");
      if(vs.size() == 3) ifun.doit.insert((string)"vec2arr");

    findFunction(tmp, "Rot90()");
      if(vs.size() == 3) ifun.doit.insert((string)"Rot90");

    findFunction(tmp, "minFactorList()");
      if(vs.size() == 3) ifun.doit.insert((string)"minFactorList");

    findFunction(tmp, "maxFactorList()");
      if(vs.size() == 3) ifun.doit.insert((string)"maxFactorList");

    findFunction(tmp, "FactorList()");
      if(vs.size() == 3) ifun.doit.insert((string)"FactorList");

    findFunction(tmp, "FactorMList()");
      if(vs.size() == 3) ifun.doit.insert((string)"FactorMList");

    findFunction(tmp, "EulerPhiList()");
      if(vs.size() == 3) ifun.doit.insert((string)"EulerPhiList");

    findFunction(tmp, "LinearEquationMod2()");
      if(vs.size() == 3) ifun.doit.insert((string)"LinearEquationMod2");

    findFunction(tmp, "LinearEquation()");
      if(vs.size() == 3) ifun.doit.insert((string)"LinearEquation");

    findFunction(tmp, "LexicographicGE()");
      if(vs.size() == 3) ifun.doit.insert((string)"LexicographicGE");

    findFunction(tmp, "cReader_ll()");
      if(vs.size() == 3) ifun.doit.insert((string)"cReader_ll");

    findFunction(tmp, "cReader_eof()");
      if(vs.size() == 3) ifun.doit.insert((string)"cReader_eof");

    findFunction(tmp, "cntPrime()");
      if(vs.size() == 3) ifun.doit.insert((string)"cntPrime");

    findFunction(tmp, "arrMerge()");
      if(vs.size() == 3) ifun.doit.insert((string)"arrMerge");

    findFunction(tmp, "arrMergeD()");
      if(vs.size() == 3) ifun.doit.insert((string)"arrMergeD");


    findFunction(tmp, "popFirst()");
      if(vs.size() == 3) ifun.doit.insert((string)"multiset_popFirst");

    findFunction(tmp, "getFirst()");
      if(vs.size() == 3) ifun.doit.insert((string)"multiset_getFirst");

    findFunction(tmp, "popLast()");
      if(vs.size() == 3) ifun.doit.insert((string)"multiset_popLast");

    findFunction(tmp, "getLast()");
      if(vs.size() == 3) ifun.doit.insert((string)"multiset_getLast");

    findFunction(tmp, "popFirst()");
      if(vs.size() == 3) ifun.doit.insert((string)"set_popFirst");

    findFunction(tmp, "getFirst()");
      if(vs.size() == 3) ifun.doit.insert((string)"set_getFirst");

    findFunction(tmp, "popLast()");
      if(vs.size() == 3) ifun.doit.insert((string)"set_popLast");

    findFunction(tmp, "getLast()");
      if(vs.size() == 3) ifun.doit.insert((string)"set_getLast");

    findFunction(tmp, "getClosest()");
      if(vs.size() == 3) ifun.doit.insert((string)"multiset_getClosest");

    findFunction(tmp, "getClosestL()");
      if(vs.size() == 3) ifun.doit.insert((string)"multiset_getClosestL");

    findFunction(tmp, "getClosest()");
      if(vs.size() == 3) ifun.doit.insert((string)"set_getClosest");

    findFunction(tmp, "getClosestL()");
      if(vs.size() == 3) ifun.doit.insert((string)"set_getClosestL");

    findFunction(tmp, "getClosest()");
      if(vs.size() == 3) ifun.doit.insert((string)"arr_getClosest");

    findFunction(tmp, "getClosestL()");
      if(vs.size() == 3) ifun.doit.insert((string)"arr_getClosestL");

    findFunction(tmp, "setEdge()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_setEdge");

    findFunction(tmp, "setDirectEdge()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_setDirectEdge");

    findFunction(tmp, "setEdgeRootedTree()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_setEdgeRootedTree");

    findFunction(tmp, "reverse()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_reverse");

    findFunction(tmp, "reduce()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_reduce");

    findFunction(tmp, "getDist()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_getDist");

    findFunction(tmp, "TreeDiameter()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_TreeDiameter");

    findFunction(tmp, "getDistTree_WeightedNode_max()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_getDistTree_WeightedNode_max");

    findFunction(tmp, "getDistPairMatrix()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_getDistPairMatrix");

    findFunction(tmp, "SubTreeSize()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_SubTreeSize");

    findFunction(tmp, "SubTreeWeight()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_SubTreeWeight");

    findFunction(tmp, "cntShortest()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_cntShortest");

    findFunction(tmp, "scc()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_scc");

    findFunction(tmp, "bcc()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_bcc");

    findFunction(tmp, "articulation()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_articulation");

    findFunction(tmp, "shortestPath()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_shortestPath");

    findFunction(tmp, "TopologicalSort()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_TopologicalSort");

    findFunction(tmp, "longestPath_length()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_longestPath_length");

    findFunction(tmp, "Grundy()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_Grundy");

    findFunction(tmp, "preorder()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_preorder");

    findFunction(tmp, "anUndirectedCycle()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_anUndirectedCycle");

    findFunction(tmp, "shortestCycle()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_shortestCycle");

    findFunction(tmp, "shortestUndirectedCycle_length()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_shortestUndirectedCycle_length");

    findFunction(tmp, "shortestUndirectedCycle_length()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_shortestUndirectedCycle_length_node");

    findFunction(tmp, "maxIndependenceSet()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_maxIndependenceSet");

    findFunction(tmp, "countIndependenceSet()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_countIndependenceSet");

    findFunction(tmp, "bipartite()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_bipartite");

    findFunction(tmp, "Rerooting()");
      if(vs.size() == 3) ifun.doit.insert((string)"graph_Rerooting");

    findFunction(tmp, "setEdge()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_setEdge");

    findFunction(tmp, "setDirectEdge()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_setDirectEdge");

    findFunction(tmp, "setEdgeRootedTree()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_setEdgeRootedTree");

    findFunction(tmp, "getDist()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_getDist");

    findFunction(tmp, "getDistDense()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_getDistDense");

    findFunction(tmp, "getDistForest()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_getDistForest");

    findFunction(tmp, "BellmanFord()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_BellmanFord");

    findFunction(tmp, "getDist01()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_getDist01");

    findFunction(tmp, "MST_Prim_cost()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_MST_Prim_cost");

    findFunction(tmp, "Rerooting()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_Rerooting");

    findFunction(tmp, "numOfDaysInMonth()");
      if(vs.size() == 3) ifun.doit.insert((string)"numOfDaysInMonth1");

    findFunction(tmp, "numOfDaysInMonth()");
      if(vs.size() == 3) ifun.doit.insert((string)"numOfDaysInMonth2");

    findFunction(tmp, "getSum()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_getSum");

    findFunction(tmp, "setSum()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_getSum");

    findFunction(tmp, "setConstLenLeft()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_ConstLenLeft");

    findFunction(tmp, "ConstLenLeft()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_ConstLenLeft");

    findFunction(tmp, "ConstLenLeftCyclic()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_ConstLenLeft");

    findFunction(tmp, "setConstLenRight()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_ConstLenRight");

    findFunction(tmp, "ConstLenRight()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_ConstLenRight");

    findFunction(tmp, "ConstLenRightCyclic()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_ConstLenRight");

    findFunction(tmp, "setDHist()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_dHist");

    findFunction(tmp, "dHist()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_dHist");

    findFunction(tmp, "setSHist()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_sHist");

    findFunction(tmp, "sHist()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_sHist");

    findFunction(tmp, "setPrevLE()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_PrevLE");

    findFunction(tmp, "PrevLE()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_PrevLE");

    findFunction(tmp, "setPrevLT()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_PrevLT");

    findFunction(tmp, "PrevLT()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_PrevLT");

    findFunction(tmp, "setPrevGE()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_PrevGE");

    findFunction(tmp, "PrevGE()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_PrevGE");

    findFunction(tmp, "setPrevGT()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_PrevGT");

    findFunction(tmp, "PrevGT()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_PrevGT");

    findFunction(tmp, "setNextLE()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_NextLE");

    findFunction(tmp, "NextLE()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_NextLE");

    findFunction(tmp, "setNextLT()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_NextLT");

    findFunction(tmp, "NextLT()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_NextLT");

    findFunction(tmp, "setNextGE()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_NextGE");

    findFunction(tmp, "NextGE()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_NextGE");

    findFunction(tmp, "setNextGT()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_NextGT");

    findFunction(tmp, "NextGT()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr1d_NextGT");

    findFunction(tmp, "getSum()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_getSum");

    findFunction(tmp, "getSumBorder()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_getSum");

    findFunction(tmp, "getSum45()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_getSum45");

    findFunction(tmp, "getSum45Border()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_getSum45");

    findFunction(tmp, "setConstLenLeft()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_ConstLenLeft");

    findFunction(tmp, "ConstLenLeft()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_ConstLenLeft");

    findFunction(tmp, "setConstLenRight()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_ConstLenRight");

    findFunction(tmp, "ConstLenRight()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_ConstLenRight");

    findFunction(tmp, "setConstLenUp()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_ConstLenUp");

    findFunction(tmp, "ConstLenUp()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_ConstLenUp");

    findFunction(tmp, "setConstLenDown()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_ConstLenDown");

    findFunction(tmp, "ConstLenDown()");
      if(vs.size() == 3) ifun.doit.insert((string)"Arr2d_ConstLenDown");

    findFunction(tmp, "InnerProd()");
      if(vs.size() == 3) ifun.doit.insert((string)"Point2d_InnerProd");

    findFunction(tmp, "CrossProd()");
      if(vs.size() == 3) ifun.doit.insert((string)"Point2d_CrossProd");

    findFunction(tmp, "xysortA()");
      if(vs.size() == 3) ifun.doit.insert((string)"Point2d_xysortA");

    findFunction(tmp, "argsortA()");
      if(vs.size() == 3) ifun.doit.insert((string)"Point2d_argsortA");

    findFunction(tmp, "CCW()");
      if(vs.size() == 3) ifun.doit.insert((string)"Point2d_CCW");

    findFunction(tmp, "ConvexHull_sorted()");
      if(vs.size() == 3) ifun.doit.insert((string)"Point2d_ConvexHull");

    findFunction(tmp, "ConvexHull()");
      if(vs.size() == 3) ifun.doit.insert((string)"Point2d_ConvexHull");

    findFunction(tmp, "PolygonArea2()");
      if(vs.size() == 3) ifun.doit.insert((string)"Point2d_PolygonArea2");

    findFunction(tmp, "Determinant()");
      if(vs.size() == 3) ifun.doit.insert((string)"Determinant_Modint");

    findFunction(tmp, "Determinant()");
      if(vs.size() == 3) ifun.doit.insert((string)"Determinant_modint");

    findFunction(tmp, "Determinant()");
      if(vs.size() == 3) ifun.doit.insert((string)"Determinant_Mint");

    findFunction(tmp, "Determinant()");
      if(vs.size() == 3) ifun.doit.insert((string)"Determinant_mint");


    findFunction(tmp, "cntSubsequence<>()");
      if(vs.size() == 4) ifun.doit.insert((string)"cntSubsequence");

    findFunction(tmp, "sumPrime<>()");
      if(vs.size() == 4) ifun.doit.insert((string)"sumPrime");



    findFunction(tmp, "getDistT()");
      if(vs.size() == 3) ifun.doit.insert((string)"wgraph_getDistT");
      /*
            {
                "name" : "getDistT",
                "argc" : 3,
                "condition" : "getDistT",
                "dependencies" : [
                    "wgraph_getDistT"
                ]
            }
        */
    findFunction(tmp, "getDistT<>()");
      if(vs.size() == 4) ifun.doit.insert((string)"wgraph_getDistT");
        /*
            {
                "name" : "getDistT",
                "argc" : 4,
                "condition" : "getDistT",
                "dependencies" : [
                    "wgraph_getDistT"
                ]
            }
        */

}

int main(){
    test();
}

//generator for dependencies.json

ofstream fout("ans.json");

    fout << "[" <<endl;

    auto getSourceCode = [&](string & x){
        //split along \n
        vector<string> lines;
        stringstream ss(x);
        string line;
        while(getline(ss, line)){
            lines.push_back(line);
        }
        return lines;
    };

    auto writeArray = [&] (vector<string> & x){
        for(int i = 0; i < x.size(); ++i){
            string line =  x[i];
            //replace all " with \\\"
            string newline;
            newline = "";
            for(int i = 0; i < line.length(); ++i){
              switch(line[i]){
                case '\"':
                  newline += "\\";
                  newline += "\"";
                  break;
                case '\\':
                  newline += "\\\\";
                  break;
                default:
                  newline += line[i];
                  break;
              }
            }
            line = newline;
            

            if(i == x.size()-1){
              fout << "\"" << line << "\"" << endl;
              break;
            }
            fout << "\"" << line << "\"" << "," << endl;
        }
    };
    int priori = 0;
    for(string & x : name){
        fout << "{" <<endl;
        fout << "    " << "\"name\":\"" << x << "\"," << endl;
        //"sourceCode":
        vector<string> sourceCode = getSourceCode(func[x]);
        fout << "    " << "\"sourceCode\":[" << endl;
        writeArray(sourceCode);
        fout << "]," << endl;
        vector<string> dep = need[x];
        dep.push_back(parent[x]);
        //"dependencies": 
        fout << "    " << "\"dependencies\":[" << endl;
        writeArray(dep);
        fout << "]," << endl;
        //"identifiers": 
        fout << "    " << "\"identifiers\":[]," << endl;
        //"priorities":
        fout << "    " << "\"priorities\":" << priori << "," << endl;
        //"type": 
        fout << "    " << "\"type\":\"" << place[x] << "\"" << endl;
        fout << "}," << endl;
        priori++;
 
    }
    fout << "]" <<endl;
