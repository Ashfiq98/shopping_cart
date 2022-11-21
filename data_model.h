// product,item,cart
#include<bits/stdc++.h>
using namespace std;

class Item;
class Cart;

class Product{
    int id;
    string name;
    int price;
public:
   // Assignment
   Product(){}
   Product(int u_id,string name,int price){
    id = u_id;
    this->name = name;
    this->price = price;
   }
   
   string getDisplayName(){
    return name+" : TK. "+to_string(price)+"\n";
   }
     
   string Nickname(){
    return name.substr(0,1);
   }

   friend class Item;
   friend class Cart;
};


class Item{
    Product product;
    int quantity;
public:
   // initialization list
   Item(){}
   Item(Product p,int q): product(p),quantity(q){};
   int getPriceOfItem(){
        return quantity*product.price;
   }
   
   string getInfoOfItem()
   {
    return to_string(quantity)+" x "+product.name+" TK. "+to_string(quantity*product.price)+"\n";
   }
   friend class Cart;
};

class Cart{
    unordered_map<int,Item> items;
public:
    void addProduct(Product product){
        if(items.count(product.id)==0)
        {
          Item newItem(product,1);
          items[product.id] = newItem;
        }
        else
         {
            items[product.id].quantity+=1;
         }
    }
    int getTotal(){
        //Todo:
        int total = 0;
        for(auto pairItem: items)
        {
            auto item = pairItem.second;
            total+=item.getPriceOfItem();
        }
        return total;
    }

    string viewCart()
    {
        if(items.empty())
        {
             return "Cart is Empty!!\n";
        }
        string itemizedList;
        
        int cart_total = getTotal();

        for(auto pairItem: items)
        {
          auto item = pairItem.second;
            itemizedList.append("                                  "+item.getInfoOfItem()); 

        }
      
        return itemizedList + "                                  -------------------------\n                                  Total Bill : TK. "+to_string(cart_total)+'\n';
    }
    bool isEmpty(){
        return items.empty();
    }
};