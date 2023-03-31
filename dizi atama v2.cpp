#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void dizi(int eleman, int baslangic, int bitis, int yeni_deger)
{
    int dizi[eleman];
    srand(time(NULL));
    
    for(int i = 0; i < eleman; i++)		//girdi kadar rastgele elemanli dizi atama
    {
        dizi[i] = rand();
    }
    
    // dizinin ortalamasi
    int sum = 0;
    for(int i = 0; i < eleman; i++)
    {
        sum += dizi[i];
    }
    int ort = sum / eleman;
    
    printf("Dizinin ortalamasi: %d\n", ort);
    
    // Indis arasýndaki degerleri degistirme
    if(baslangic >= 0 && bitis < eleman && baslangic <= bitis)
    {
        for(int i = baslangic; i <= bitis; i++)
        {
            dizi[i] = yeni_deger; // belli indis araligindaki degeri yeniden atama
        }
    }
    
    // diziyi ekrana yazdirma
    printf("Dizi elemanlari: ");
    for(int i = 0; i < eleman; i++)
    {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}
int main()
{
    int eleman,secim,ort=0;
    int bitis,yeni_deger,baslangic;
    printf("1-Dizi kac elemanli olsun?:\n");
    scanf("%d",&eleman);
    printf("2-Hangi eleman araligini degistirmek istersiniz?:\n");
    scanf("%d",&secim);
    printf("3-Dizinizin ortalamasý:\n");
    
    dizi(eleman,baslangic,bitis,yeni_deger);
    
    return 0;
}
