#include <iostream>
#include <string>
using namespace std;

class Book{
private:

    string name;
    int price;
    int pages;

public:
    //setter fn
    void setName(string s){
        name = s;
    }
    void setPrice(int p){
        price = p;
    }
    void setPages(int page){
        pages = page;
    }
    // getter fn

    string getName(){
        return name;
    }

    int getPrice(){
        return price;
    }

    int getPages(){
        return pages;
    }

    // member fn
    int countBooks(int p){  // number of books having price less than price
        if (price>p) return 1;
        else return 0;
    }

    bool isBookPresent(string book){ // if the book of particular name is present or not
        if (book == name) return true;
        else return false;
    }

};



int main(){
    Book b1;
    b1.setName("hcv");
    b1.setPages(400);
    cout<<b1.getName()<<"\n";

    cout<<b1.isBookPresent("harry")<<"\n";
    cout<<b1.countBooks(200)<<"\n";
    
}