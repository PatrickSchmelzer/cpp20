#pragma once
#include <iostream>
#include <tuple>
#include <utility>
#include <span>
#include <string>

template<typename T>
void getAttribute(T& t, std::span<uint8_t> data, uint8_t& offset) {
	uint32_t attribute = 0U;
	for (uint8_t idx = 0U; idx < sizeof(T); ++idx) {
		attribute |= (data[offset] << (8 * idx));
		offset += 1U;
	}
	t = static_cast<T>(attribute);
}

template<typename... Args>
std::tuple<Args...> getAttributes(std::span<uint8_t> data) {
	std::tuple<Args...> attributes;
	uint8_t offset = 0U;
	std::apply([&](auto&... ps) {((getAttribute(ps, data, offset)), ...); }, attributes);
	return attributes;
}
// usage
//int main() {
//	uint8_t arr[]{ 0x04,0x03,0x00,0x01 };
//	const auto [one] = getAttributes<uint32_t>({ arr, 4U });
//	std::cout << std::hex << one << std::endl;
//	const auto [first, second, third] = getAttributes<uint8_t, uint8_t, uint16_t>({ arr, 4U });
//	std::cout << std::to_string(first) << "\t" << std::to_string(second) << "\t" << std::to_string(third) << std::endl;
//	return 0;
//}
