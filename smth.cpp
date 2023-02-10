#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

/**
 *  @brief Class Articles that stores the name of the product, the country of export, the volume of products supplied and the amount of sale
 */

class Articles {
public:
    /**
    *  @brief Parameterized constructor
    *  @details Used for initialization an object of the class according to the parameters
    *  @param name_ parameter with string type, country_ parameter with string type, volume_ parameter with the float type, summa_ parameter with the float type
    *  @return There is no return value
    *  @code
        Articles(string name_, string country_, float volume_, float summa_){
            name = name_;
            country = country_;
            volume = volume_;
            summa = summa_;
            }
    *  @endcode
    */

    Articles(string name_, string country_, float volume_, float summa_){
        name = name_;
        country = country_;
        volume = volume_;
        summa = summa_;
    }

    /**
    *  @brief Default constructor
    *  @details Used for filling class fields with empty strings or zeros, depending on the datd type of the field (string or float)
    *  @param There are no parameters
    *  @return There is no return value
    *  @code
        Articles() {
            name = "";
            country = "";
            volume = 0;
            summa = 0;
        }
    *  @endcode
    */

    Articles() {
        name = "";
        country = "";
        volume = 0;
        summa = 0;
    }

    /**
     *  @brief Input file stream constructor
     *  @details Used for reading class fields from the input file stream
     *  @param File stream reference
     *  @return There is no return value
     *  @code
        Articles(ifstream& in) {
            in >> name >> country >> volume >> summa;
        }
     *  @endcode
     */

    Articles(ifstream& in) {
        in >> name >> country >> volume >> summa;
    }

    /**
     *  @brief Destructor
     *  @details Used for default description of class methods
     *  @param There are no parameters
     *  @return There is no return value
     *  @code
        ~Articles() {}
     *  @endcode
     */

    ~Articles() {}

    /**
     *  @brief Assignment operator
     *  @details Used for storing a value of fields in the object specified by the left operand from object specified by the right operand
     *  @param There are no parameters
     *  @return There is no return value
     *  @code
        Articles& Articles::operator= (const Articles& art) {
            name = art.name;
            country = art.country;
            volume = art.volume;
            summa = art.summa;

            return *this;
        }
     *  @endcode
     */

    Articles& operator= (const Articles& art);

    /**
     *  @brief Output operator
     *  @details Used for output a class object (class fields) to the output stream; a friend of class
     *  @param Output stream reference and constant reference of class object
     *  @return Output steam
     *  @code
        ostream& operator<< (ostream& out, const Articles& art){
            out << art.name << " ";
            out << art.country << " ";
            out << art.volume << " ";
            out << art.summa << " ";

            out << endl;

            return out;
        }
     *  @endcode
     */

    friend ostream& operator<< (ostream& out, const Articles& art);

    /**
     *  @brief Class fields
     *  @details The name of the product, the country of export, the volume of products supplied and the amount of sale
     *  @code
            string name;
            string country;
            float volume;
            float summa;
     *  @endcode
     */

    string name;
    string country;
    float volume;
    float summa;

};

Articles& Articles::operator= (const Articles& art) {
        name = art.name;
        country = art.country;
        volume = art.volume;
        summa = art.summa;

        return *this;
    }

ostream& operator<< (ostream& out, const Articles& art){
    out << art.name << " ";
    out << art.country << " ";
    out << art.volume << " ";
    out << art.summa << " ";

    out << endl;

    return out;
}

/**
 *  @brief Comparison operator for strict equality
 *  @details Used for checking strict equality between left and right operands
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if parameters are equal, False otherwise
 *  @code
    bool operator== (const Articles& art1, const Articles& art2) {
        return ((art1.name == art2.name) && (art1.volume == art2.volume) && (art1.country == art2.country));
    }
 *  @endcode
 */

bool operator== (const Articles& art1, const Articles& art2) {
    return ((art1.name == art2.name) && (art1.volume == art2.volume) && (art1.country == art2.country));
}

/**
 *  @brief Comparison operator for strict inequality
 *  @details Used for checking strict inequality between left and right operands
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if parameters are unequal, False otherwise
 *  @code
    bool operator!= (const Articles& art1, const Articles& art2) {
        return !(art1 == art2);
    }
 *  @endcode
 */

bool operator!= (const Articles& art1, const Articles& art2) {
    return !(art1 == art2);
}

/**
 *  @brief Comparison operator "strictly greater"
 *  @details Used for checking whether the left operand is strictly greater than the right one
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if left operand is strictly greater than right operand, False otherwise
 *  @code
    bool operator> (const Articles& art1, const Articles& art2) {
        if (art1 == art2)
            return false;

        if (art1.name != art2.name)
            return (art1.name > art2.name);

        if (art1.volume != art2.volume)
            return (art1.volume > art2.volume);

        if (art1.country != art2.country)
            return (art1.country > art2.country);
    }
 *  @endcode
 */

bool operator> (const Articles& art1, const Articles& art2) {
    if (art1 == art2)
        return false;

    if (art1.name != art2.name)
        return (art1.name > art2.name);

    if (art1.volume != art2.volume)
        return (art1.volume > art2.volume);

    if (art1.country != art2.country)
        return (art1.country > art2.country);
}

/**
 *  @brief Comparison operator "not strictly greater"
 *  @details Used for checking whether the left operand is not strictly greater than the right one
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if left operand is not strictly greater than right operand, False otherwise
 *  @code
    bool operator>= (const Articles& art1, const Articles& art2) {
        return ((art1 > art2) || (art1 == art2));
    }
 *  @endcode
 */

bool operator>= (const Articles& art1, const Articles& art2) {
    return ((art1 > art2) || (art1 == art2));
}

/**
 *  @brief Comparison operator "strictly less"
 *  @details Used for checking whether the left operand is strictly less than the right one
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if left operand is strictly less than right operand, False otherwise
 *  @code
    bool operator< (const Articles& art1, const Articles& art2) {
        return !(art1 >= art2);
    }
 *  @endcode
 */

bool operator< (const Articles& art1, const Articles& art2) {
    return !(art1 >= art2);
}

/**
 *  @brief Comparison operator "not strictly less"
 *  @details Used for checking whether the left operand is not strictly less than the right one
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if left operand is not strictly less than right operand, False otherwise
 *  @code
    bool operator< (const Articles& art1, const Articles& art2) {
        return !(art1 >= art2);
    }
 *  @endcode
 */

bool operator<= (const Articles& art1, const Articles& art2) {
    return ((art1 < art2) || (art1 == art2));
}

/**
 *  @brief Template function of bubble sorting
 *  @details Used for sorting data array by the bubble sorting method
 *  @param Pointer to the first element of the sorted array with data type T, array size with data type size_t
 *  @return There is no return value
 *  @code
    template <typename T>
    void bubleSort (T* A, size_t n) {
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - 1 - i; j++){
                if (A[j] > A[j + 1])
                    swap(A[j], A[j + 1]);
            }
        }
    }
 *  @endcode
 */

template <typename T>
void bubbleSort (T* A, size_t n) {
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
        }
    }
}

/**
 *  @brief Template function of shaker sorting
 *  @details Used for sorting data array by the shaker sorting method
 *  @param Pointer to the first element of the sorted array with data type T, array size with data type size_t
 *  @return There is no return value
 *  @code
    template <typename T>
    void shakerSort (T* A, size_t n) {
        int low = 0, up = n - 1;

        int last;

        T tmp;

        while (low < up) {
            last = -1;

            for (int i = low; i < up; i++) {
                if (A[i] > A[i + 1]) {
                    tmp = A[i];
                    A[i] = A[i + 1];
                    A[i + 1] = tmp;
                    last = i;
                }
            }

            up = last;

            last = n;
            for (int i = up - 1; i >= low; i--) {
                if (A[i] > A[i + 1]) {
                    tmp = A[i];
                    A[i] = A[i + 1];
                    A[i + 1] = tmp;
                    last = i;
                }
            }

            low = last + 1;
        }
    }
 *  @endcode
 */

template <typename T>
void shakerSort (T* A, size_t n) {
    int low = 0, up = n - 1;

    int last;

    T tmp;

    while (low < up) {
        last = -1;

        for (int i = low; i < up; i++) {
            if (A[i] > A[i + 1]) {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                last = i;
            }
        }

        up = last;

        last = n;
        for (int i = up - 1; i >= low; i--) {
            if (A[i] > A[i + 1]) {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                last = i;
            }
        }

        low = last + 1;
    }
}

/**
 *  @brief Template function of merge sorting
 *  @details Used for sorting data array by the merge sorting method
 *  @param Pointer to the first element of the sorted array with data type T, array size with data type size_t
 *  @return There is no return value
 *  @code
    template <typename T>
    void mergeSort(T* A, size_t n){
        if (n == 1)
            return;

        mergeSort(A, n / 2);
        mergeSort(&A[n / 2], n - n / 2);

        int i = 0, j = n / 2, c = 0;

        T* N = new T[n];

        while(c < n){
            if (i == n / 2){
                N[c] = A[j];
                j++;
            }
            else
            if (j == n){
                N[c] = A[i];
                i++;
            }
            else
            if (A[i] < A[j]){
                N[c] = A[i];
                i++;
            }
            else
            {
                N[c] = A[j];
                j++;
            }
            c++;
        }

        for (size_t i = 0; i < n; i++)
            A[i] = N[i];
    }
 *  @endcode
 */

template <typename T>
void mergeSort(T* A, size_t n){
    if (n == 1)
        return;

    mergeSort(A, n / 2);
    mergeSort(&A[n / 2], n - n / 2);

    int i = 0, j = n / 2, c = 0;

    T* N = new T[n];

    while(c < n){
        if (i == n / 2){
            N[c] = A[j];
            j++;
        }
        else
        if (j == n){
            N[c] = A[i];
            i++;
        }
        else
        if (A[i] < A[j]){
            N[c] = A[i];
            i++;
        }
        else
        {
            N[c] = A[j];
            j++;
        }
        c++;
    }

    for (size_t i = 0; i < n; i++)
        A[i] = N[i];
}

/**
 *  @brief Main function
 *  @details Used for reading samples from files, sorting these samples using one of the methods described above and writing the sorted samples to new files
 *  @param There is no parameters
 *  @return There is no return value
 *  @code
    template <typename T>
    void mergeSort(T* A, size_t n){
        if (n == 1)
            return;

        mergeSort(A, n / 2);
        mergeSort(&A[n / 2], n - n / 2);

        int i = 0, j = n / 2, c = 0;

        T* N = new T[n];

        while(c < n){
            if (i == n / 2){
                N[c] = A[j];
                j++;
            }
            else
            if (j == n){
                N[c] = A[i];
                i++;
            }
            else
            if (A[i] < A[j]){
                N[c] = A[i];
                i++;
            }
            else
            {
                N[c] = A[j];
                j++;
            }
            c++;
        }

        for (size_t i = 0; i < n; i++)
            A[i] = N[i];
    }
 *  @endcode
 */

int main(){
    Articles *d_100 = new Articles[100], *d_500 = new Articles[500], *d_1000 = new Articles[1000], *d_5000 = new Articles[5000], *d_10000 = new Articles[10000], *d_50000 = new Articles[50000], *d_100000 = new Articles[100000];

    ifstream f_100("100.txt");
    if (f_100.is_open())
        for (size_t i = 0; i < 100; i++)
            d_100[i] = Articles(f_100);
    f_100.close();

    ifstream f_500("500.txt");
    if (f_500.is_open())
        for (size_t i = 0; i < 500; i++)
            d_500[i] = Articles(f_500);
    f_500.close();

    ifstream f_1000("1000.txt");
    if (f_1000.is_open())
        for (size_t i = 0; i < 1000; i++)
            d_1000[i] = Articles(f_1000);
    f_1000.close();

    ifstream f_5000("5000.txt");
    if (f_5000.is_open())
        for (size_t i = 0; i < 5000; i++)
            d_5000[i] = Articles(f_5000);
    f_5000.close();

    ifstream f_10000("10000.txt");
    if (f_10000.is_open())
        for (size_t i = 0; i < 10000; i++)
            d_10000[i] = Articles(f_10000);
    f_10000.close();

    ifstream f_50000("50000.txt");
    if (f_50000.is_open())
        for (size_t i = 0; i < 50000; i++)
            d_50000[i] = Articles(f_50000);
    f_50000.close();

    ifstream f_100000("100000.txt");
    if (f_100000.is_open())
        for (size_t i = 0; i < 100000; i++)
            d_100000[i] = Articles(f_100000);
    f_100000.close();

    int whatSort;
    cout << "Print what sort you want: 1 - buble sort, 2 - shaker sort, 3 - merge sort\n" ;
    cin >> whatSort;

    if (whatSort == 1) {
        cout << "Time for number 100: \n";
        clock_t s_100 = clock();
        bubbleSort(d_100, 100);
        cout << (double)(clock() - s_100) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 500: \n";
        clock_t s_500 = clock();
        bubbleSort(d_500, 500);
        cout << (double)(clock() - s_500) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 1000: \n";
        clock_t s_1000 = clock();
        bubbleSort(d_1000, 1000);
        cout << (double)(clock() - s_1000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 5000: \n";
        clock_t s_5000 = clock();
        bubbleSort(d_5000, 5000);
        cout << (double)(clock() - s_5000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 10000: \n";
        clock_t s_10000 = clock();
        bubbleSort(d_10000, 10000);
        cout << (double)(clock() - s_10000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 50000: \n";
        clock_t s_50000 = clock();
        bubbleSort(d_50000, 50000);
        cout << (double)(clock() - s_50000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 100000: \n";
        clock_t s_100000 = clock();
        bubbleSort(d_100000, 100000);
        cout << (double)(clock() - s_100000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        ofstream o_100("b100.txt"),
                 o_500("b500.txt"),
                 o_1000("b1000.txt"),
                 o_5000("b5000.txt"),
                 o_10000("b10000.txt"),
                 o_50000("b50000.txt"),
                 o_100000("b100000.txt");

        for (size_t i = 0; i < 100; i++)
            o_100 << d_100[i];

        for (size_t i = 0; i < 500; i++)
            o_500 << d_500[i];

        for (size_t i = 0; i < 1000; i++)
            o_1000 << d_1000[i];

        for (size_t i = 0; i < 5000; i++)
            o_5000 << d_5000[i];

        for (size_t i = 0; i < 10000; i++)
            o_10000 << d_10000[i];

        for (size_t i = 0; i < 50000; i++)
            o_50000 << d_50000[i];

        for (size_t i = 0; i < 100000; i++)
            o_100000 << d_100000[i];

        o_100.close();
        o_500.close();
        o_1000.close();
        o_5000.close();
        o_10000.close();
        o_50000.close();
        o_100000.close();
    }

    if (whatSort == 2) {
        cout << "Time for number 100: \n";
        clock_t s_100 = clock();
        shakerSort(d_100, 100);
        cout << (double)(clock() - s_100) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 500: \n";
        clock_t s_500 = clock();
        shakerSort(d_500, 500);
        cout << (double)(clock() - s_500) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 1000: \n";
        clock_t s_1000 = clock();
        shakerSort(d_1000, 1000);
        cout << (double)(clock() - s_1000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 5000: \n";
        clock_t s_5000 = clock();
        shakerSort(d_5000, 5000);
        cout << (double)(clock() - s_5000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 10000: \n";
        clock_t s_10000 = clock();
        shakerSort(d_10000, 10000);
        cout << (double)(clock() - s_10000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 50000: \n";
        clock_t s_50000 = clock();
        shakerSort(d_50000, 50000);
        cout << (double)(clock() - s_50000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 100000: \n";
        clock_t s_100000 = clock();
        shakerSort(d_100000, 100000);
        cout << (double)(clock() - s_100000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        ofstream o_100("s100.txt"),
                 o_500("s500.txt"),
                 o_1000("s1000.txt"),
                 o_5000("s5000.txt"),
                 o_10000("s10000.txt"),
                 o_50000("s50000.txt"),
                 o_100000("s100000.txt");

        for (size_t i = 0; i < 100; i++)
            o_100 << d_100[i];

        for (size_t i = 0; i < 500; i++)
            o_500 << d_500[i];

        for (size_t i = 0; i < 1000; i++)
            o_1000 << d_1000[i];

        for (size_t i = 0; i < 5000; i++)
            o_5000 << d_5000[i];

        for (size_t i = 0; i < 10000; i++)
            o_10000 << d_10000[i];

        for (size_t i = 0; i < 50000; i++)
            o_50000 << d_50000[i];

        for (size_t i = 0; i < 100000; i++)
            o_100000 << d_100000[i];

        o_100.close();
        o_500.close();
        o_1000.close();
        o_5000.close();
        o_10000.close();
        o_50000.close();
        o_100000.close();
    }

    if (whatSort == 3) {
        cout << "Time for number 100: \n";
        clock_t s_100 = clock();
        mergeSort(d_100, 100);
        cout << (double)(clock() - s_100) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 500: \n";
        clock_t s_500 = clock();
        mergeSort(d_500, 500);
        cout << (double)(clock() - s_500) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 1000: \n";
        clock_t s_1000 = clock();
        mergeSort(d_1000, 1000);
        cout << (double)(clock() - s_1000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 5000: \n";
        clock_t s_5000 = clock();
        mergeSort(d_5000, 5000);
        cout << (double)(clock() - s_5000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 10000: \n";
        clock_t s_10000 = clock();
        mergeSort(d_10000, 10000);
        cout << (double)(clock() - s_10000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 50000: \n";
        clock_t s_50000 = clock();
        mergeSort(d_50000, 50000);
        cout << (double)(clock() - s_50000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        cout << "Time for number 100000: \n";
        clock_t s_100000 = clock();
        mergeSort(d_100000, 100000);
        cout << (double)(clock() - s_100000) * 1000 / CLOCKS_PER_SEC << "ms \n \n";

        ofstream o_100("m100.txt"),
                 o_500("m500.txt"),
                 o_1000("m1000.txt"),
                 o_5000("m5000.txt"),
                 o_10000("m10000.txt"),
                 o_50000("m50000.txt"),
                 o_100000("m100000.txt");

        for (size_t i = 0; i < 100; i++)
            o_100 << d_100[i];

        for (size_t i = 0; i < 500; i++)
            o_500 << d_500[i];

        for (size_t i = 0; i < 1000; i++)
            o_1000 << d_1000[i];

        for (size_t i = 0; i < 5000; i++)
            o_5000 << d_5000[i];

        for (size_t i = 0; i < 10000; i++)
            o_10000 << d_10000[i];

        for (size_t i = 0; i < 50000; i++)
            o_50000 << d_50000[i];

        for (size_t i = 0; i < 100000; i++)
            o_100000 << d_100000[i];

        o_100.close();
        o_500.close();
        o_1000.close();
        o_5000.close();
        o_10000.close();
        o_50000.close();
        o_100000.close();
    }
}
