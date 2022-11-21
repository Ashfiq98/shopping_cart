#include"data_model.h"

vector<Product> allProducts = {
   Product(01,"Apple",120),
   Product(02,"Mango",100),
   Product(03,"Guava",160),
   Product(04,"Strawberry",600),
   Product(05,"Pineapple",90),
   Product(05,"Banana",250),
};
Product* chooseProduct(){
    string productList;
    cout<<"Available products \n";
    cout<<"------------------\n\n";
    for(auto product: allProducts)
    {
        productList.append(product.getDisplayName());
    }
    cout<<productList<<"\n";
    cout<<"Please, Press first letter to find your favourite product from list.. "; 

    string choice;
    cin>>choice;

    for(int i=0;i<allProducts.size();i++)
    {
        if(allProducts[i].Nickname()==choice)
          return &allProducts[i]; 
    }
    cout<<"Sorry!This product is not available\n";
    return NULL;
}
bool checkOut(Cart &cart)
{
    if(cart.isEmpty())
    return false;

    int total = cart.getTotal();
    cout<<"          Please, Pay in Cash only\n          Enter your amount.... ";
    int paid;
    cin>>paid;
    if(paid>=total)
    {
        cout<<"\n\n\n          Change - '"<<paid-total<<"' TK\n";
        cout<<"--------------------------Thank you for shopping!--------------------------\n";
        cout<<"-------------------------- Assalamu Alaikum--------------------------\n";
        return true;
    }
    else{
        cout<<"\nSorry! not enough cash!\n";
        return false;
    }
}
int main(){
    // Product p1(01,"Banana",120);
    
    // cout<<p1.getDisplayName();
    // Item i(p1,3);
    // cout<<i.getPriceOfItem()<<"\n";
    // cout<<i.getInfoOfItem();
    string action;
    Cart cart;
    while(1){
    cout<<"Please, select an action :\n i.   Add item \n ii.  View cart \n iii. Checkout \n";
   
    cin>>action;

    if(action=="i")
    {
       Product *product = chooseProduct();
       if(product!=NULL){
          cout<<"Added to the cart -> "<<product->getDisplayName()<<"\n";
         cart.addProduct(*product);
       }
    }
    else if(action=="ii")
    {
      cout<<"                                  All of your carted Items : \n";
      cout<<"                                  -------------------------\n";
      cout<<cart.viewCart();
    }
    else if(action=="iii")
    {
       cart.viewCart();
       if(checkOut(cart))
       break;
       else
       {
        cout<<"Checkout again kindly... \n\n";
       }
    }
    else{
        cout<<"Sorry! wrong input\n Please, try again\n\n";
    }
    
    }
}