/*
 * @Author: w 2652289370@qq.com
 * @Date: 2023-04-27 17:10:25
 * @LastEditors: w 2652289370@qq.com
 * @LastEditTime: 2023-05-10 11:29:52
 * @FilePath: /ros/src/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑     永不宕机     永无BUG
 */


#include "DataStream.h"
#include <iostream>
#include <vector>

using namespace std;

using namespace w::serialize;
int main()
{
    DataStream ds;
    bool a = false;
    string b = "19u0";
    string c;
   
    vector<string> d;
    d.push_back("10.02A");
    d.push_back("20");


    double f = 3.5;
    char s = 'b';
    ds << d << f;

    bool r1, r2;
    vector<string> res;
    double rf;
    string sr;
    ds >> res >> rf;
    // ds.show();
    cout << rf << endl;
   
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    
    
    return 0;
}