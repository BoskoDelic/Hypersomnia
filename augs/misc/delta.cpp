#include "delta.h"
#include "stepped_timing.h"

namespace augs {
	double fixed_delta::in_seconds() const {
		return fixed_delta_ms / 1000.0;
	}

	unsigned fixed_delta::get_steps_per_second() const {
		return steps_per_second;
	}
	
	double fixed_delta::total_time_passed_in_seconds() const {
		return total_steps_passed * in_seconds();
	}
	
	unsigned long long fixed_delta::get_total_steps_passed() const {
		return total_steps_passed;
	}

	double fixed_delta::in_milliseconds() const {
		return fixed_delta_ms;
	}
	
	stepped_timestamp fixed_delta::get_timestamp() const {
		stepped_timestamp result;
		result.step = total_steps_passed;
		return result;
	}

	double variable_delta::in_seconds() const {
		return variable_delta_ms / 1000.0;
	}

	double variable_delta::in_milliseconds() const {
		return variable_delta_ms;
	}

	double variable_delta::view_interpolation_ratio() const {
		return interpolation_ratio;
	}
	
	fixed_delta variable_delta::get_fixed() const {
		return fixed;
	}

	double variable_delta::total_time_passed_in_seconds() const {
		return fixed.total_time_passed_in_seconds() + view_interpolation_ratio() * fixed.in_seconds();
	}
}