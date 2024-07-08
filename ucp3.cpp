#include <iostream>
#include <exception>
using namespace std;

class MasukUniversitas
{
protected:
    int uangPendaftaran;
    int uangsemesterpertama;
    int uangbangunan;
    int totalbiaya;

public:
    MasukUniversitas()
        : uangPendaftaran(0), uangsemesterpertama(0), uangbangunan(0), totalbiaya(0) {}

    virtual string namaJalurMasuk() = 0;
    virtual int hitungtotal() = 0;
    virtual void tampiltotal() = 0;
    virtual void input() = 0;

    void setUangPendaftaran(int nilai)
    {
        this->uangPendaftaran = nilai;
    }
    int getUangPendaftaran() const
    {
        return uangPendaftaran;
    }

    void setUangSemesterPertama(int nilai)
    {
        this->uangsemesterpertama = nilai;
    }
    int getUangSemesterPertama() const
    {
        return uangsemesterpertama;
    }

    void setUangBangunan(int nilai)
    {
        this->uangbangunan = nilai;
    }
    int getUangBangunan() const
    {
        return uangbangunan;
    }

    void setTotalBiaya(int nilai)
    {
        this->totalbiaya = nilai;
    }
    int getTotalBiaya() const
    {
        return totalbiaya;
    }
};

class SNBT : public MasukUniversitas
{
public:
    string namaJalurMasuk() override
    {
        return "SNBT";
    }

    void input() override
    {
        int up, usp, ub;
        cout << "Masukkan Uang Pendaftaran : ";
        cin >> up;
        setUangPendaftaran(up);

        cout << "Masukkan Uang Semester Pertama : ";
        cin >> usp;
        setUangSemesterPertama(usp);

        cout << "Masukkan Uang Bangunan : ";
        cin >> ub;
        setUangBangunan(ub);
    }

    int hitungtotal() override
    {
        return getUangSemesterPertama() + getUangBangunan() + getUangPendaftaran();
    }

    void tampiltotal() override
    {
        setTotalBiaya(hitungtotal());
        cout << "Total Biaya Jalur " << namaJalurMasuk() << " Adalah : " << getTotalBiaya() << endl;

        if (getTotalBiaya() > 4000000)
        {
            cout << "Kategori : Mahal\n";
            cout << "Rekomendasi : Tidak Direkomendasikan\n";
        }
        else if (getTotalBiaya() > 2000000)
        {
            cout << "Kategori : Sedang\n";
            cout << "Rekomendasi : Dipertimbangkan\n";
        }
        else
        {
            cout << "Kategori : Murah\n";
            cout << "Rekomendasi : Direkomendasikan\n";
        }
    }
};

class SNBP : public MasukUniversitas
{
public:
    string namaJalurMasuk() override
    {
        return "SNBP";
    }

    void input() override
    {
        int up, usp;
        cout << "Masukkan Uang Pendaftaran : ";
        cin >> up;
        setUangPendaftaran(up);

        cout << "Masukkan Uang Semester Pertama : ";
        cin >> usp;
        setUangSemesterPertama(usp);
    }

    int hitungtotal() override
    {
        return getUangSemesterPertama() + getUangPendaftaran();
    }

    void tampiltotal() override
    {
        setTotalBiaya(hitungtotal());
        cout << "Total Biaya Jalur " << namaJalurMasuk() << " Adalah : " << getTotalBiaya() << endl;

        if (getTotalBiaya() > 4000000)
        {
            cout << "Kategori : Mahal\n";
            cout << "Rekomendasi : Tidak Direkomendasikan\n";
        }
        else if (getTotalBiaya() > 2000000)
        {
            cout << "Kategori : Sedang\n";
            cout << "Rekomendasi : Dipertimbangkan\n";
        }
        else
        {
            cout << "Kategori : Murah\n";
            cout << "Rekomendasi : Direkomendasikan\n";
        }
    }
};

int main()
{
    MasukUniversitas* jalur;
    int pil;
    SNBP b;
    SNBT a;

    while (true)
    {
        try
        {
            cout << "Pilih Jalur Masuk : \n";
            cout << "1. SNBT\n";
            cout << "2. SNBP\n";
            cout << "3. Keluar\n";
            cout << "Masukkan Pilihan : ";
            cin >> pil;

            switch (pil)
            {
            case 1:
                jalur = &a;
                jalur->namaJalurMasuk();
                jalur->input();
                jalur->hitungtotal();
                jalur->tampiltotal();
                break;
            case 2:
                jalur = &b;
                jalur->namaJalurMasuk();
                jalur->input();
                jalur->hitungtotal();
                jalur->tampiltotal();
                break;
            case 3:
                return 0;
            default:
                cout << "Pilihan tidak Valid\n";
                continue;
            }

            jalur->input();
            jalur->tampiltotal();
        }
        catch (exception &e)
        {
            cout << e.what() << '\n';
        }
    }
}