
/* LAB2 WOLF SHEEP CABBAGE
 * MUDIT PRASHANT SANGHAVI

 */

#include <iostream>
using namespace std;

// LEFT = FALSE, RIGHT = TRUE

bool c = false, s = false, w = false, b = false;

int print(bool c, bool s, bool w, bool b){
//Left  --------------------  Right
    cout<<"Left  --------------------  Right"<<endl;

    if(w==false)cout<<"w ";
    else cout<<"  ";

    if(s==false)cout<<"s ";
    else cout<<"  ";

    if(c==false)cout<<"c ";
    else cout<<"  ";

    cout<<"                      ";

    if(w==true)cout<<"w ";
    else cout<<"  ";

    if(s==true)cout<<"s ";
    else cout<<"  ";

    if(c==true)cout<<"c ";
    else cout<<"  ";

    cout<<endl;

    if (b==false)cout<<"boat"<<endl;
    else cout<<"                        boat"<<endl;
    return 0;
}

int reset(bool c,bool s,bool w,bool b){
    c=false;
    s=false;
    w=false;
    b=false;

    print(c,s,w,b);


    return 0;
}

int change (bool x){
    switch(x) {
        case 'c':

            break;
    }
    if (x== true)x = false;
    else x = true;

    cout<<x<<endl;

    return x;
}

int check(bool c,bool s,bool w,bool b){
    if (c&&s&&w&&b==true){
        cout << "Wolf, sheep and cabbage are all on right side!"<<endl;
        cout << "Congratulations! You win!" << endl;

    }
    else if (((c==s)&&(c!=b))||((s==w)&&(s!=b))){
        cout<<"YOU FAILED!!"<<endl;
        cout<<"Try Again!" <<endl;
        reset(c,s,w,b);
        check(c,s,w,b);
    }
    else{
        cout<<"Item to carry ( ";
        if(w==b)cout<< " w:wolf,";
        if(s==b)cout<<" s:sheep,";
        if(c==b)cout<<" c:cabbage,";
        cout<<" n:nothing):"<<endl;




        string item;
        cin>>item;
        if(item=="w"){change(w);change(b);}
        else if (item=="s"){change(s);change(b);}
        else if(item=="c"){change(c);change(b);}
        else if(item=="n"){change(b);}
//change(b);
        else cout<<"Please provide valid input"<<endl;

        print(c,s,w,b);
//cout<<"Left  --------------------  Right"<<endl;

    }
    check(c,s,w,b);
    return 0;
}
//Wolf, sheep and cabbage are all on right side!
// Congratulations! You win!



int main(){

// bool c = false, s = false, w = false, b = false;

    reset(c,s,w,b);

    check(c,s,w,b);

    return 0;
}
