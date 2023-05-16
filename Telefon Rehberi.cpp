#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//kayýt için gerekli bir fonksiyon bellek pointer belli bir text dosyasýna atýlabilir oradan çekilebilir.
void kayitlar()
{
    char ad[50], soyad[50], telefon[20];
    FILE *dosya;

    // Dosyayý açma veya oluþturma iþlemi
    dosya = fopen("rehber.txt", "a+"); // "a+" modu dosyayý yazma ve dosya sonuna ekleme modu olarak açar, dosya yoksa olusturur.

    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    printf("Ad: ");
    scanf("%s", ad);

    printf("Soyad: ");
    scanf("%s", soyad);

    printf("Telefon: ");
    scanf("%s", telefon);

    // Dosyaya kayýt yazma iþlemi
    fprintf(dosya, "Ad: %s\tSoyad: %s\tTelefon: %s\n", ad, soyad, telefon);

    printf("Kayit basariyla eklendi!\n");

    // Dosyayý kapatma
    fclose(dosya);
}
//4 fonksiyonlu rehber				2.FONKSÝYON
void arama()
{
    FILE *dosya;
    char ad[50], soyad[50];
    char satir[150];

    dosya = fopen("rehber.txt", "r+");	//"r+" modu dosyayi acar ve icerigini okuyup bellege kaydeder.
    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    printf("\nKimi aramak istiyorsunuz?:\n");
    printf("Ad: ");
    scanf("%s", ad);
    printf("Soyad: ");
    scanf("%s", soyad);

    while (fgets(satir, sizeof(satir), dosya))				//dosyadan aldigimiz bilgi stringinin uzunlugunu olcuyoruz.Belli bir uzunluktayken;
    {
        if (strstr(satir, ad) != NULL && strstr(satir, soyad) != NULL)		//bilgilerdeki ad ve soyad eslesiyorsa kayit bulunuyor.
        {
            printf("Kayit bulundu:\n");
            printf("%s", satir);
            fclose(dosya);
            return;
        }
        else
        {
        	printf("Boyle bir kayit yok!\n");				//eslesmiyorsa kayit bulamiyor.
		}
    }

    printf("Kayit bulunamadi!\n");
    fclose(dosya);
}

void guncelle()
{
    FILE *dosya;
    FILE *gecici;								//bir orjinal ve bir gecici rehber dosyasi olusturuyoruz ki guncelleyebilelim.
    char ad[50], soyad[50];					
    char satir[150];
    char yeniTelefon[20];

    dosya = fopen("rehber.txt", "r");
    gecici = fopen("gecici.txt", "w");
    if (dosya == NULL || gecici == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    printf("\nKaydi guncellemek istediginiz kisinin adini ve soyadini giriniz:\n");
    printf("Ad: ");																		//kaydini degistirmek istedigimiz kisinin bilgilerini giriyoruz.
    scanf("%s", ad);
    printf("Soyad: ");
    scanf("%s", soyad);

    while (fgets(satir, sizeof(satir), dosya))							//girdigimiz bilginin uzunlugu dogrultusunda yine isimlerin eslesmesine bakiyoruz eger eslesiyorsa:
    {
        if (strstr(satir, ad) != NULL && strstr(satir, soyad) != NULL)
        {
            printf("Mevcut telefon numarasi: %s", satir);						//yeni telefon numarasini giriyoruz.
            printf("Yeni telefon numarasini giriniz: ");
            scanf("%s", yeniTelefon);
            fprintf(gecici, "Ad: %s\tSoyad: %s\tTelefon: %s\n", ad, soyad, yeniTelefon);
            printf("Kayit guncellendi!\n");
        }
        else
        {
            fprintf(gecici, "%s", satir);					//eslesen bulunmadiysa tekrar giriyoruz.
        }
    }

    fclose(dosya);
    fclose(gecici);

    remove("rehber.txt");				//burada orjinal dosyayi yenilenmis haliyle degistirip adini degistiriyoruz.
    rename("gecici.txt", "rehber.txt");
}
void silme()
{
	char ad[50], soyad[50];					
    char satir[150];
    char bosluk[1];
    
	FILE *dosya;
	FILE *gecici;
	dosya= fopen("rehber.txt","r");			//yeniden onceden kayitli olan dosyamizi acip okuyoruz
	gecici= fopen("gecici.txt","w");		//gecici dosyamizi acip bilgileri ona yaziyoruz.
	if (dosya == NULL)
	{
		printf("Dosya acilamadi!\n");
		return;
	}
	
	printf("Silmek istediginiz kisinin Adi:\n");
	scanf("%s", ad);
    printf("Soyadi: ");
    scanf("%s", soyad);
    
    while(fgets(satir,sizeof(satir), dosya))
    {
    	if(strstr(satir,ad)!= NULL && strstr(satir,soyad)!= NULL)
    	{
    		printf("Bosluk tusuna basip Entera basiniz:%s",satir);
    		scanf("%s", bosluk);
		}
	}
}

//Telefon rehberi menusu		3.FONKSÝYON MAÝN FONKSÝYONU
int main()
{
    int secim;
    printf("---------| TELEFON REHBERI |----------\n\n");
    printf("----| SECENEKLER |----\n");
    printf("1 - Yeni Kayit\n");
    printf("2 - Kayit Ara\n");
    printf("3 - Kayit Guncelle\n");
    printf("4 - Kayit Sil\n\n");

    printf("-Seciminiz?: ");
    scanf("%d", &secim);

    switch (secim)
    {
        case 1:
            kayitlar();
            break;
        case 2:
            arama();
            {
                printf("Bu kaydi ne yapmak istiyorsunuz?\n");
                printf("3 - Kayit Guncelle\n");
                printf("4 - Kayit Sil\n\n");
            }
            break;
        case 3:
            guncelle();
            break;
        case 4:
            silme();
            break;
        default:
            printf("Gecersiz secim!\n");
            break;
    }

    return 0;
}
