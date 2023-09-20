// CplusplusThreadStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <cstdio>
#include <iostream>
#include <thread> // 쓰레드 
#include <vector>
using std::thread; // 출력 위한 std 사용
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end,
    int* result) {
    int sum = 0;
    for (auto itr = start; itr < end; ++itr) {
        sum += *itr;
    }
    *result = sum;

    // 쓰레드의 id를 구한다.
    thread::id this_id = std::this_thread::get_id();
    printf("쓰레드 %x에서 %d부터 %d까지 계산한 결과 : %d\n", this_id, *start, *(end - 1), sum);

}

int main()
{
    printf("Hello world!");
    return 0;
    //vector<int> data(10000);
    //for (int i = 0; i < 10000; i++) {
    //    data[i] = i;
    //}

    //// 각 쓰레드에서 계산된 부분 합을 저장하는 벡터
    //vector<int> partial_sums(4);
    //
    //vector<thread> workers;
    //for (int i = 0;i < 4; i++) {
    //    workers.push_back(thread(worker, data.begin() + i * 2500,
    //        data.begin() + (i + 1) * 2500, &partial_sums[i]));
    //}

    //for (int i = 0;i < 4; i++) {
    //    workers[i].join();
    //}

    //int total = 0;
    //for (int i = 0;i < 4;i++) {
    //    total += partial_sums[i];
    //}

    //std::cout << "전체 합: " << total << std::endl;
}

