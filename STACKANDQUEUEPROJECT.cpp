#include<iostream>
#include<vector>
#include<string>
#include <algorithm>

class Stack{
    public:
        std::vector <char> stack;
    bool validPara(std::string parenthesis){
       std::vector <char> stack;

       for(int i=0; i< parenthesis.length(); i++){
           if (parenthesis[i] == '{' || parenthesis[i]== '(' || parenthesis[i]== '['){
               stack.push_back(parenthesis[i]);
           }
           else{
               if (stack.size() == 0 && (parenthesis[i] == ')' || parenthesis[i]== '}' || parenthesis[i]==']')){
                   std::cout<<"Invalid"<<std::endl;
                   return false;
               }
               else if(stack.size() != 0){
                    if(isalnum(parenthesis[i])){
                        continue;
                    }
                    else {
                        char value = stack.back();
                        if( value == '(' && parenthesis[i] != ')'){
                                if(isalnum(parenthesis[i])|| parenthesis[i] == ':' || parenthesis[i] == ';'|| parenthesis[i] == ' '){
                                    continue;
                                }
                                else{
                                    std::cout<<"Invalid"<<std::endl;
                                    return false;
                                }
                        }

                        if(value == '{' && parenthesis[i] != '}'){
                                if(isalnum(parenthesis[i])|| parenthesis[i] == ':' || parenthesis[i] == ';'|| parenthesis[i] == ' '){
                                    continue;
                                }
                                else{
                                    std::cout<<"Invalid"<<std::endl;
                                    return false;
                                }
                        }

                        if(value == '[' && parenthesis[i] != ']'){
                                if(isalnum(parenthesis[i])|| parenthesis[i] == ':' || parenthesis[i] == ';'|| parenthesis[i] == ' '){
                                    continue;
                                }
                                else{
                                    std::cout<<"Invalid"<<std::endl;
                                    return false;
                                }
                        }
                    }
                   stack.pop_back();
               }
           }
       }

        if(stack.size() != 0){
            std::cout<<"Invalid"<<std::endl;
            return false;
        }
        std::cout<<"Valid"<<std::endl;
        return true;

    }

    int indexError(std::string parenthesis){
       std::vector <char> stack;

       for(int i=0; i< parenthesis.length(); i++){
           if (parenthesis[i] == '{' || parenthesis[i]== '(' || parenthesis[i]== '['){
               stack.push_back(parenthesis[i]);
           }
           else{
               if (stack.size() == 0 && (parenthesis[i] == ')' || parenthesis[i]== '}' || parenthesis[i]==']')){
                   return i;
               }
               else if (stack.size() !=0){
                   char value = stack[stack.size()-1];
                   if( value == '(' && parenthesis[i] != ')'){
                        if(isalnum(parenthesis[i])|| parenthesis[i] == ':' || parenthesis[i] == ';'|| parenthesis[i] == ' '){
                            continue;
                        }
                        else{
                            return i;
                        }
                   }
                   if(value == '{' && parenthesis[i] != '}'){
                        if(isalnum(parenthesis[i])|| parenthesis[i] == ':' || parenthesis[i] == ';' || parenthesis[i] == ' '){
                            continue;
                        }
                        else{
                            return i;
                        }
                   }
                   if(value == '[' && parenthesis[i] != ']'){
                        if(isalnum(parenthesis[i])|| parenthesis[i] == ':' || parenthesis[i] == ';'|| parenthesis[i] == ' '){
                            continue;
                        }
                        else{
                            return i;
                        }
                   }
                   stack.pop_back();
               }
           }
       }

        if(stack.size() != 0){
            return parenthesis.length()-1;
        }
        return -1;

    }

    int minPara(std::string parenthesis){
       std::vector <char> stack;
       int min = 0;
       for(int i=0; i< parenthesis.length(); i++){
           if (parenthesis[i] == '{' || parenthesis[i]== '(' || parenthesis[i]== '['){
               stack.push_back(parenthesis[i]);
           }
           else{ // not open
               if (stack.size() == 0 && (parenthesis[i] == ')' || parenthesis[i]== '}' || parenthesis[i]==']')){
                   min++;
                }  
                else if (isalnum(parenthesis[i])|| parenthesis[i] == ':' || parenthesis[i] == ';'|| parenthesis[i] == ' '){
                    continue;
                }
                else{
                    stack.pop_back();
                }
           }
               
           
       }
        while(stack.size() != 0){
            min++;
            stack.pop_back();
        }
        return min;
    }
    int scorePara(std::string parenthesis){
       std::vector <char> stack;
       int min = 0;
       int score = 0;
       for(int i=0; i< parenthesis.length(); i++){
           if (parenthesis[i] == '{' || parenthesis[i]== '(' || parenthesis[i]== '['){
               stack.push_back(parenthesis[i]);
           }
           else{
               if (stack.size() == 0 && (parenthesis[i] == ')' || parenthesis[i]== '}' || parenthesis[i]==']')){
                   min++;

               }
               else if (stack.size() != 0){
                   char value = stack[stack.size()-1];
                   if( value == '(' && parenthesis[i] != ')'){
                        if(isalnum(parenthesis[i])|| parenthesis[i] == ':' || parenthesis[i] == ';'){
                            continue;
                        }
                        else{
                            min++;
                        }
                   }
                   if(value == '{' && parenthesis[i] != '}'){
                        if(isalnum(parenthesis[i])|| parenthesis[i] == ':' || parenthesis[i] == ';'){
                            continue;
                        }
                        else{
                            min++;
                        }
                   }
                   if(value == '[' && parenthesis[i] != ']'){
                        if(isalnum(parenthesis[i])|| parenthesis[i] == ':' || parenthesis[i] == ';'){
                            continue;
                        }
                        else{
                            min++;
                        }
                   }
                   stack.pop_back();
                   score++;
               }
           }
       }

        while(stack.size() != 0){
            min++;
            stack.pop_back();
        }
        std::cout<< score<<std::endl;
        return 0;
    }
};
class Queue{
    public:
    std::vector <std::string> queue; 

    void enqueue(std::string s){
        std::string regstring = "";
        int count= 0;
        for(int i = 0; i<s.length(); i++){

            if (regstring.length() == 7) {
                regstring += s[i];
                reverse(regstring.begin(),regstring.end());
                queue.push_back(regstring);
                regstring = "";
            } else {
                regstring += s[i];
            }
        }

        if (regstring.length() != 0) {
            reverse(regstring.begin(),regstring.end());
            queue.push_back(regstring);
        }
    }

    void processMsg(){
        std::string processedstring;
        while(!queue.empty()){
            std::string split = queue[0];
            reverse(split.begin(),split.end());
            processedstring += split;
            queue.erase(queue.begin());
        }
        std::cout<<processedstring<<std::endl;
    }
};

int main(){
    Stack s1;
    s1.validPara("(([]))");
    s1.minPara("(([]))");
    s1.scorePara("(([]))");
    s1.validPara("(([])");
    std::cout<<s1.indexError("(([))")<<std::endl;
    s1.minPara("(([])");
    s1.validPara("(([{}))");
    std::cout<<s1.indexError("(([[}])")<<std::endl;
    s1.minPara("(([{}))");
    s1.scorePara("(([{}))");
    std::cout<<s1.indexError("({}[]()[)")<<std::endl;
    s1.validPara("(([))");
    s1.minPara("(([))");
    std::cout<<s1.indexError("[({)]")<<std::endl;
    s1.validPara("(([{[{({})}]}]))");
    s1.minPara("(([{[{({})}]}]))");
    s1.scorePara("(([{[{({})}]}]))");
    s1.validPara("(([[{[{({})}]))");
    s1.validPara("(([[{[{({})}]}])]))");
    s1.scorePara("(([[{[{({})}]}])]))");
    std::cout<<s1.indexError("(([[{{({})]}])]))")<<std::endl;
    s1.validPara("(())");
    s1.validPara("(())");
    s1.validPara("void function(){}");
    s1.scorePara("void function(){}");
    s1.validPara("void function(");
    s1.minPara("void function(");
    s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
    s1.scorePara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
    s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}");
    s1.validPara("void function(std::string expre){if(expre){return 1;else{return 0;");
    s1.minPara("void function(std::string expre){if(expre){return 1;else{return 0;");
    std::cout<<s1.indexError("void function(std::string expre){if(expre){return 1;else{return 0;")<<std::endl;
    Queue q1;
    q1.enqueue("This is a secure message.");
    q1.processMsg();
    q1.enqueue("The product I received is damaged. What should I do?");
    q1.processMsg();
    q1.enqueue("I need assistance with setting up my new device");
    q1.processMsg();
    q1.enqueue("The website is not loading properly on my browser.");
    q1.processMsg();
    q1.enqueue("I accidentally placed the wrong order. Can it be canceled?");
    q1.processMsg();
    q1.enqueue("This is your project3. Have a happy thanksgiving!!! Hahaha");
    q1.processMsg();
    q1.enqueue("I forgot my password and can't reset it. Help, please! Do you provide technical support for mobile devices?");
    q1.processMsg();
    q1.enqueue("The software update is causing issues on my computer. The response time on your website is very slow.");
    q1.processMsg();
    return 0;
}
