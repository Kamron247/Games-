#include "sodoku.cc"
#include <gmock/gmock.h>


/*
References:
1. https://simplifycpp.org/?id=a0166

*/

class MockSodoku : public Sodoku
{
    public:
        MOCK_METHOD(vector<vector<int>>, createRandomBoard, (), (override));
        MOCK_METHOD(bool, isValidBoard, (vector<vector<int>>), (override));
};