#include <stdio.h>

int main() {
    int stock[9] = {10,10,10,10,10,10,10,10,10};
    char again;
    do
    {
    printf("==== Food Vending Machine ====\n"
            "1. apple - 12 บาท มีจำนวน : %d\n",stock[0]);
    printf("2. melon - 15 บาท มีจำนวน : %d\n",stock[1]);
    printf("3. Candy - 7 บาท มีจำนวน : %d\n",stock[2]);
    printf("4. Chips - 10 บาท มีจำนวน : %d\n",stock[3]);
    printf("5. Chocolate - 20 บาท มีจำนวน : %d\n",stock[4]);
    printf("6. Juice - 18 บาท มีจำนวน : %d\n",stock[5]);
    printf("7. Milk - 14 บาท มีจำนวน : %d\n",stock[6]);
    printf("8. Water - 5 บาท มีจำนวน : %d\n",stock[7]);
    printf("9. Bread - 8 บาท มีจำนวน : %d\n",stock[8]);
 

        int item;
        printf("===============================\n");
        printf("กรุณาเลือกสินค้าหมายเลข (1-9): ");
        scanf("%d", &item);
        printf("คุณเลือกสินค้าหมายเลข %d\n", item);

        char food_name[9][15] = {
            "apple", "melon", "Candy",
            "Chips", "Chocolate", "Juice",
            "Milk", "Water", "Bread"
        };
        int price[9] = {12, 15, 7, 10, 20, 18, 14, 5, 8};
        

        if (item < 1 || item > 9)
        {
            printf("ไม่มีสินค้าหมายเลข : %d" ,item);
            return 0;
        }
        else
        {
        printf("สินค้าชื่อ: %s ราคาสินค้า: %d บาท\n",food_name[item-1], price[item-1]);
        }
        

        int money = price[item-1];
        int coin;

        printf("ที่ต้องจ่าย: %d บาท\n", money);

        while(money > 0) {
            printf("===============================");
            printf("\nหยอดเหรียญได้เฉพาะ (10,5,2,1)หยอดเหรียญ : "); /*\nต้องการยกเลิกกด 0\n*/
            scanf("%d", &coin);

            if(coin == 10 || coin == 5 || coin == 2 || coin == 1) {
                money = money - coin;
                if(money > 0) {
                    printf("ยอดเงินคงเหลือ: %d บาท\n", money);
                } else if(money < 0) {
                    printf("เงินทอน: %d บาท\n", -money);
                }
            } 
            else {
                printf("รับเฉพาะเหรียญ 10,5,2,1 เท่านั้น!\n");
                printf("ยอดเงินคงเหลือ: %d บาท\n", money);
            }
            
        }
        stock[item-1]--;
        printf("คุณได้รับสินค้า: %s\n", food_name[item-1]);
        printf("\nต้องการซื้ออีกไหม? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("ขอบคุณที่ใช้บริการ\n");
    return 0;



}
