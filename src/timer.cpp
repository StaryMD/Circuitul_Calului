#include <chrono>

namespace my {
	struct Timer {
		std::chrono::steady_clock::time_point start;

		Timer() {
			reset();
		}

		void reset() {
			start = std::chrono::steady_clock::now();
		}

		double elapsed_time() {
			std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
			std::chrono::duration<double> interval = now - start;
			return interval.count();
		}
	};
}
