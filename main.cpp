#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{

    int stockA = 10, stockB = 8, stockC = 8;
    double priceA=30;
    double priceB=50;
    double priceC=100;
    double total;
    double discount = 0.10;
    double final_price;
    double final_total;
    int shipping_fee = 15;
    int loyalty_points;
    int quantityA, quantityB, quantityC;
    int payment_method;
    float transaction_fee, total_transaction_fee;
    int customerType;
    float VIPDiscount, total_VIPDiscount;
    string couponCode;
    double coupon, couponDiscount, total_after_coupon;
    const string SAVE10 = "SAVE10";
    double couponValue;
    int region;
    double salesTax, taxRate, taxRate1, total_after_tax;
    int return0, returnA, returnB, returnC;
    double total_after_return;
    char redeemPoints;
    double pointsDiscount, pointsDiscount2, final_points_Discount;
    char giftWrap;
    double giftWrap1, giftWrap2, giftWrap3, giftWrap4;

    cout<<" "<<endl;
    cout<<"---Welcome to the ECommerce Store---"<<endl;
    cout<<"You can avail discount of 10% on shopping above $200."<<endl;
    cout<<"Shipping free on all orders above $150!!"<<endl;
    cout<<" "<<endl;
    cout<<"Enter the Quantity for Product A (10 in Stock):"<<endl;
    cin>>quantityA;
    if (quantityA > stockA)
    {
        cout << "Sorry, only " << stockA << " units of Product A are available." << endl;
        return 0;
    }
    cout<<"Enter the Quantity for Product B (8 in Stock): "<<endl;
    cin>>quantityB;
    if (quantityB > stockB)
    {
        cout << "Sorry, only " << stockB << " units of Product B are available." << endl;
        return 0;
    }
    cout<<"Enter the Quantity for Product C (8 in Stock): "<<endl;
    cin>>quantityC;
    if (quantityC > stockC)
    {
        cout << "Sorry, only " << stockC << " units of Product C are available." << endl;
        return 0;
    }


    cout<<""<<endl;
    total = (quantityA * priceA) + (quantityB * priceB) + (quantityC * priceC);
    cout<<"Total Price: $"<<total<<endl;

    (total >= 200) ? discount : total;
    discount = total*discount;
    final_price = total - discount;

    (total >= 200) ? cout<<"You have availed a discount of 10%= $"<<final_price<<endl: cout<<""<<endl;

    final_total = total + shipping_fee;
    (final_price >= 150) ? cout<<"Your Shipping is free!!"<<endl : cout<<"Your Total with $15 Shipping= $"<<final_total<<endl;

    loyalty_points = (final_total >= 300) ? 50 : 20;

    cout<<"You have Earned "<< loyalty_points<<" Loyalty Points."<<endl;

    cout<<""<<endl;
    cout<<"Enter type of Customer:"<<endl;
    cout<<"1: Regular"<<endl;
    cout<<"2: VIP (Additional 5% OFF)"<<endl;
    cin>>customerType;

    VIPDiscount = 0.05 * final_total;
    total_VIPDiscount = final_total - VIPDiscount;


    cout<<""<<endl;
    (customerType == 1) ? cout<<"Your Total Amount is= $"<<final_total<<endl : cout<<"Your Total after VIP Discount is= $"<<total_VIPDiscount<<endl;


    cout<<""<<endl;
    cout<<"Select Payment Method: "<<endl;
    cout<<"1: Credit Card (2% Transaction Fee) "<<endl;
    cout<<"2: Paypal (3% Transaction Fee)"<<endl;
    cout<<"3: Cash (No Transaction Fee)"<<endl;
    cin>>payment_method;

    transaction_fee = (customerType == 1) ? (payment_method == 1 ? 0.02 * final_price : (payment_method == 2 ? 0.03 * final_price : 0.0))
        : (customerType == 2) ? (payment_method == 1 ? 0.02 * total_VIPDiscount : (payment_method == 2 ? 0.03 * total_VIPDiscount : 0.0)): 0.0;
    cout<<""<<endl;
    cout<<"Your Transaction Fee: $"<<transaction_fee<<endl;
    total_transaction_fee = (customerType == 1) ? final_price + transaction_fee
       : (customerType == 2)? total_VIPDiscount + transaction_fee : 0.0;
    cout<<"Your Total after Transaction Fee: $"<<total_transaction_fee<<endl;

    cout << endl;
    cout << "Enter Coupon Code (If any): ";
    cin >> couponCode;

    couponValue = (couponCode == SAVE10) ? 10.0 : 0.0;
    total_after_coupon = total_transaction_fee - couponValue;

    cout << (couponValue > 0 ? "Your amount after Coupon is: $" : "Invalid Coupon, Your total is= $")
      << (couponValue > 0 ? total_after_coupon : total_transaction_fee) << endl;

    cout<<""<<endl;
    cout<<"Enter your Region= "<<endl;
    cout<<"1: Asia (5% Tax)"<<endl;
    cout<<"2: Europe (10% Tax)"<<endl;
    cout<<"3: America (8% Tax)"<<endl;
    cin>>region;

    taxRate = (region == 1) ? 0.05 : (region == 2) ? 0.10 : 0.08;

    taxRate1 = (couponValue > 0) ? total_after_coupon * taxRate : total_transaction_fee * taxRate;
    total_after_tax = (couponValue > 0) ? total_after_coupon + taxRate1 : total_transaction_fee + taxRate1;

    cout << "Your amount after Tax is: $" << total_after_tax << endl;


    cout<<""<<endl;
    cout<<"Order Summary:"<<endl;
    cout << "Product A (x" << quantityA << "): $" << priceA * quantityA << endl;
    cout << "Product B (x" << quantityB << "): $" << priceB * quantityB << endl;
    cout << "Product C (x" << quantityC << "): $" << priceC * quantityC << endl;
    cout <<"Subtotal Amount is: $" << total << endl;
    (total >= 200) ? cout<<"You have availed a discount of 10%: $"<<discount<<endl: cout<<""<<endl;
    (final_price >= 150) ? cout<<"Your Shipping is free!!"<<endl : cout<<"Your Shipping Fee is: $"<<shipping_fee<<endl;
    (customerType == 1) ? cout<<"Not eligible for VIP Discount: $"<<final_price<<endl : cout<<"Your VIP Discount is= $"<<VIPDiscount<<endl;
    cout<<"Transaction Fee: $"<<transaction_fee<<endl;
    cout << (couponValue > 0 ? "Your Coupon Discount is: $" : "Your Coupon was invalid.")
      << (couponValue > 0 ? couponValue : 0.0) << endl;
    salesTax = (couponValue > 0) ? (total_after_coupon * taxRate) : (total_transaction_fee * taxRate);
    cout << "Sales Tax For Your Region is= $" << salesTax << endl;

    cout<<"Your Total Bill is: $"<< total_after_tax<<endl;

    cout<<""<<endl;
    cout<<"Would you like to return any of your products?" <<endl;
    cout<<"1: Enter 0 to Skip"<<endl;
    cout<<"2: Enter 1 to Proceed"<<endl;
    cin>>return0;
    if (return0 == 0)
    {
        cout << "You have skipped this" << endl;
    }

    if (return0 == 1)
    {
        cout<<"Product A: "<<endl;
        cin>>returnA;
        if (returnA > quantityA)
        {
            cout << "Sorry, only " << quantityA << " units of Product A are in your cart." << endl;
            return 0;
        }
        cout<<"Product B: "<<endl;
        cin>>returnB;
        if (returnB > quantityB)
        {
            cout << "Sorry, only " << quantityB << " units of Product B are in your cart." << endl;
            return 0;
        }
        cout<<"Product C: "<<endl;
        cin>>returnC;
        if (returnC > quantityC)
        {
            cout << "Sorry, only " << returnC << " units of Product C are in your cart." << endl;
            return 0;
        }
    }

    quantityA -= returnA;
    quantityB -= returnB;
    quantityC -= returnC;
    total_after_return = (priceA * quantityA) + (priceB * quantityB) + (priceC * quantityC);

    if (return0 == 1)
    {
        cout<<"Your Total after return is: $"<<total_after_return<<endl;
    }

    cout<<""<<endl;
    cout << "You have " << loyalty_points << " loyalty points"<<endl;
    cout<<"1 Loyalty point = $1"<<endl;
    cout<<"Do you want to redeem your Loyalty Points for discount? (Y / N):"<<endl;
    cin>>redeemPoints;

    if (redeemPoints == 'y' || redeemPoints == 'Y')
    {
        pointsDiscount = total_after_return - loyalty_points;
        pointsDiscount2 = total_after_tax - loyalty_points;
        final_points_Discount = ( return0 > 0 ) ?   pointsDiscount : pointsDiscount2;
        (return0> 0) ? cout<<"Your new amount after loyalty discount is: $"<<pointsDiscount<<endl : cout<<"Your new amount after loyalty discount is: $"<<pointsDiscount2<<endl;


    }

    if(redeemPoints == 'n' || redeemPoints == 'N')
    {
        (return0> 0) ? cout<<"Your Total is: $"<<total_after_return<<endl : cout<<"Your Total is: $"<<total_after_tax<<endl;
    }

    cout<<""<<endl;
    cout<<"Would you like to add Gift Wrapping for $5? (Y/N)"<<endl;
    cin>>giftWrap;

    if (giftWrap == 'y' || giftWrap == 'Y')
    {
        giftWrap1= total_after_return + 5;
        giftWrap2 = total_after_tax + 5;
        giftWrap3 = pointsDiscount + 5;
        giftWrap4 = pointsDiscount2 + 5;
        (return0 > 0) ? cout<<"Your new amount after adding Gift Wrap is: $"<< giftWrap3<<endl : cout<<"Your new amount after adding Gift Wrap is: $"<<giftWrap4<<endl;

    }

    if (return0 == 0)
    {
        (return0 == 0) ? cout<<"Your new amount after adding Gift Wrap is: $"<< total_after_return<<endl : cout<<"Your new amount after adding Gift Wrap is: $"<<total_after_tax<<endl;
    }

    if (giftWrap == 'N' || giftWrap == 'n')
    {
        (return0> 0) ? cout<<"Your Total is: $"<<pointsDiscount<<endl : cout<<"Your Total is: $"<<pointsDiscount2<<endl;
    }

    if(return0 == 0)
    {
        (return0> 0) ? cout<<"Your Total is: $"<<total_after_return<<endl : cout<<"Your Total is: $"<<total_after_tax<<endl;
    }


    time_t t = time(0);
    tm* now = localtime(&t);
    cout << "Order placed on: " << (now->tm_mon + 1) << '/'
         << now->tm_mday << '/' << (now->tm_year + 1900) << " at "
         << now->tm_hour << ':' << now->tm_min << endl;

    return 0;

}
 
