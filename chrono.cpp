#include<iostream>
#include<ratio>
#include<chrono>
#include<iomanip>
using namespace std;
using namespace std::chrono;

template <typename V, typename R>
ostream &operator << (ostream &os, const chrono::duration<V, R> &d)
{
    os << " [ " << d.count() << " of " << R::num << " / " << R::den << " s ] ";
    return os;
}

int main()
{
    //数值：tick类型, 对应构造入参, 分数: 秒计单位类型
    chrono::duration<int> twentySeconds(20);  
    chrono::duration<double, ratio<60>> halfMinute(0.5);     /* 60/1 秒*/
    chrono::duration<long, ratio<1, 1000>> milliSecond(1);   /* 1/1000 秒*/

    chrono::seconds tenSeconds(10);                          
    chrono::hours aDay(24); 
    chrono::milliseconds oneMillisecond(1);

    cout << aDay.count()<<" hours " << endl;

    chrono::seconds d1(42);
    chrono::milliseconds d2(10);

    cout << (d1 - d2).count() << " ms " << endl;
    cout << (d1 + d2).count() << " ms " << endl;

    chrono::duration<int, ratio<1,3>> d3(1);
    chrono::duration<int, ratio<1,5>> d4(1);
    
    cout << (d3 + d4).count() << " * 1/15s " << endl;    //number of ticks

    chrono::milliseconds ms(0);
    ms += aDay;
    --ms;
    cout << ms.count() << " ms " << endl;
    cout << chrono::nanoseconds(ms).count() << " ns " << endl;

    chrono::milliseconds d5(12);
    cout << d5 << endl;
    cout << aDay << endl;

    chrono::seconds sec(55);
    /*chrono::minutes m1 = sec; */                                       //directorly, error
    chrono::minutes m2 = chrono::duration_cast<chrono::minutes>(sec);    //type cast, right
    cout << m2.count() << " minute " << endl;                            //转型粗糙类型，信息丢失

    chrono::duration<double, ratio<60>> halfMin(0.5);
    /*chrono::seconds s1 = halfMin;*/                                    //double -> long, error
    chrono::seconds s2 = chrono::duration_cast<chrono::minutes>(halfMin);
    cout << s2.count() << " s " << endl;

    ms = chrono::milliseconds(7255042);
    chrono::hours hh = chrono::duration_cast<chrono::hours>(ms);
    chrono::minutes mm = chrono::duration_cast<chrono::minutes>(ms % hours(1));
    chrono::seconds ss = chrono::duration_cast<seconds>(ms % minutes(1));
    milliseconds msec = duration_cast<milliseconds>(ms % seconds(1));


    cout << " raw: " << hh <<"::"<<mm<<"::"<<ss<<"::"<<msec << endl;
    cout << "        " << setfill('0') << setw(2) << hh.count() << " :: "
                                       << setw(2) << mm.count() << " :: "
                                       << setw(2) << ss.count() << " :: "
                                       << setw(2) << msec.count() << endl;

    cout << "hh max: " << hh.max() << endl;
    cout << "mm max: " << mm.max() << endl;
    cout << "ss max: " << ss.max() << endl;
    cout << "msec max: " << msec.max() << endl;

    cout << "hh min: " << hh.min() << endl;
    cout << "mm min: " << mm.min() << endl;
    cout << "ss min: " << ss.min() << endl;
    cout << "msec min: " << msec.min() << endl;
    return EXIT_SUCCESS;
}

