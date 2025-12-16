#include <stdio.h>

int main() {

    char name[9][20] = {
        "Snack","Biscuit","Candy",
        "Chips","Chocolate","Juice",
        "Milk","Water","Bread"
    };

    int price[9] = {12,15,7,10,20,18,14,5,8};
    int stock[9] = {10,10,10,10,10,10,10,10,10};

    int choice, coin;
    int money = 0;

    printf("==== VENDING MACHINE ====\n");
    for(int i = 0; i < 9; i++) {
        printf("%d. %s (%d บาท) [เหลือ %d]\n",
               i+1, name[i], price[i], stock[i]);
    }

    printf("\nเลือกสินค้า: ");
    scanf("%d", &choice);
    choice--;

    if(choice < 0 || choice >= 9) {
        printf("เลือกผิด!\n");
        return 0;
    }

    if(stock[choice] == 0) {
        printf("สินค้าหมด!\n");
        return 0;
    }

    printf("คุณเลือก %s ราคา %d บาท\n", name[choice], price[choice]);

    while(money < price[choice]) {
        printf("หยอดเหรียญ (10,5,2,1): ");
        scanf("%d", &coin);

        if(coin == 10 || coin == 5 || coin == 2 || coin == 1) {
            money += coin;
            printf("เงินปัจจุบัน: %d\n", money);
        } else {
            printf("เหรียญไม่ถูกต้อง!\n");
        }
    }

    if(money > price[choice]) {
        printf("เงินทอน: %d บาท\n", money - price[choice]);
    }

    stock[choice]--;
    printf("รับสินค้า: %s\n", name[choice]);
    printf("ขอบคุณที่ใช้บริการ\n");

    return 0;
}
