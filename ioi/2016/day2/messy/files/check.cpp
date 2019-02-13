#include "testlib.h"
using namespace std;

int main(int argc, char ** argv) {
	registerTestlibCmd(argc, argv);
	quitif(ouf.readLine() != "098d134608c94f7413faac591054ee35", _sv, "Wrong secret!");
	ans.readLine(); // skip jury secret
	int n = inf.readInt();
	string verdict = ouf.readToken();
	if (verdict != "OK") {
		if (verdict == "WA") {
			quitf(_wa, "grader returned WA");
		} else {
			quitf(_sv, "unknown verdict, hacked?");
		}
	}
	ans.readToken(); //skip jury verdict
	for (int i = 0; i < n; i++) {
		int o = ouf.readInt();
		int e = ans.readInt();
		if (o != e) {
			quitf(_sv, "permutation not same despite ok, hacked?");
		}
	}
	quitf(_ok, "n = %d", n);
}
