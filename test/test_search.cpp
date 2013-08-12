#include <sstream>
#include <MTToolBox/AlgorithmRecursionSearch.hpp>
#include <MTToolBox/AbstractGenerator.hpp>
#include <UnitTest++/UnitTest++.h>
#include <NTL/GF2X.h>
#include "test_generator.hpp"

using namespace MTToolBox;
using namespace NTL;
using namespace std;

SUITE(RECURSION_SEARCH) {
    TEST(SEARCH_U32)
    {
        Tiny32 tiny(1234);
        AlgorithmRecursionSearch<uint32_t> search(tiny);
        stringstream ss;
        if (search.start(10000)) {
            search.printParam(ss);
            string str = ss.str();
            CHECK(str.find("mat1") != string::npos);
            GF2X poly = search.getMinPoly();
            CHECK(deg(poly) == tiny.bitSize());
            CHECK(search.getCount() > 0);
        }
    }
}
