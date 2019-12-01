#include<iostream>
using namespace std;
int remaind, count=0;
char item, sign='c';
bool wolf, sheep, cab, non;
void Begin(){
    cout<<"Item to carry (w: wolf, s: sheep, c: cabbage, n: nothing): \n";
    cin>>item;
}
void Line(){
    cout<<"Left  --------------------  Right \n";
}
void Left(){
    if(item=='w'&&wolf==1){
        wolf=0;}
    if(item=='s'&&sheep==1){
        sheep=0;cout << sheep << endl;}
    else if(item=='s'&&sheep==0){
        sheep=1; cout << sheep << endl;}
    if(item=='c'&&cab==1){
        cab=0;}
    if(item=='n'&&non==1){
        non=0;}
}
void Right(){
    if(item=='w'&&wolf==0){
        wolf=1;}
    if(item=='c'&&cab==0){
        cab=1;}
    if(item=='n'&&non==0){
        non=1;}
}
void PosLe(){
    if(wolf==0){
        cout<<"w";}
    else{
        cout<<" ";}
    if(sheep==0){
        cout<<" s";}
    else{
        cout<<" ";}
    if(cab==0){
        cout<<" c";}
    else{
        cout<<" ";}
}
void PosRi(){
    if(wolf==1){
        cout<<"w";}
    else{
        cout<<" ";}
    if(sheep==1){
        cout<<" s";}
    else{
        cout<<" ";}
    if(cab==1){
        cout<<" c\n";}
    else{
        cout<<"\n";}
}
void Win(){
    cout<<"Wolf, sheep and cabbage are all on right side!";
    cout<<"Congratulations! You win!";
}
void CheckL(){
    if(wolf==0 && sheep==0){
        cout<<"Game Over!";sign='a';}
    else if(sheep==0 && cab==0){
        cout<<"Game Over!";sign='a';}
}
void CheckR(){
    if(wolf==1 && sheep==1){
        cout<<"Game Over!";sign='a';}
    else if(sheep==1 && cab==1){
        cout<<"Game Over!";sign='a';}
    else if(wolf==1 && sheep==1 && cab==1){
        sign='b';}
}
void Bot(){
    remaind=count%2;
    if(remaind==0){
        cout<<"boat\n";
        count++;}
    else{
        cout<<"                            boat\n";
        count++;}
    if(count>2){
        if(remaind==0){
            CheckR();}
        else{
            CheckL();}
    }
}
void Game(){
    Begin();Line();
    Left();Right();
    PosLe(); cout<<"   \t\t\t"; PosRi(); Bot();
    switch(sign){
        case 'a':
            break;
        case 'b':
            Win();
            break;}
}
int main(){
    //Defining variables
    wolf=0, sheep=0, cab=0, non=0;
    cout<<"**************************** \n";
    cout<<"Wolf, Sheep and Cabbage Game \n";
    cout<<"**************************** \n\n";
    Line(); PosLe(); PosRi(); Bot();
    cout<<"Game Start! \n";
    //Game Part
    do{Game();}
    while(sign!='a' && sign!='b');
}


