#pragma once
#include "augs/filesystem/file.h"
#include "augs/templates/byte_type_for.h"
#include "augs/readwrite/byte_readwrite.h"

namespace augs {
	inline auto file_to_bytes(const path_type& path) {
		auto file = with_exceptions<std::ifstream>();
		file.open(path, std::ios::binary | std::ios::ate);

		const std::streamsize size = file.tellg();
		file.seekg(0, std::ios::beg);

		std::vector<std::byte> output;

		output.resize(static_cast<std::size_t>(size));
		file.read(reinterpret_cast<byte_type_for_t<std::ifstream>*>(output.data()), size);
		return output;
	}

	template <class O>
	void load_from_bytes(O& object, const path_type& path) {
		auto file = open_binary_input_stream(path);
		augs::read_bytes(file, object);
	}

	template <class O>
	O load_from_bytes(const path_type& path) {
		O object;
		load_from_bytes(object, path);
		return object;
	}

	template <class O>
	void save_as_bytes(const O& object, const path_type& path) {
		auto out = open_binary_output_stream(path);
		write_bytes(out, object);
	}

	inline void save_as_bytes(const std::vector<std::byte>& bytes, const path_type& path) {
		auto out = open_binary_output_stream(path);
		out.write(reinterpret_cast<const byte_type_for_t<decltype(out)>*>(bytes.data()), bytes.size());
	}

	template <class ContainerType>
	void read_map_until_eof(const path_type& path, ContainerType& into) {
		auto source = open_binary_input_stream(path);

		while (source.peek() != EOF) {
			typename ContainerType::key_type key{};
			typename ContainerType::mapped_type value{};

			augs::read_bytes(source, key);
			augs::read_bytes(source, value);

			into.emplace(std::move(key), std::move(value));
		}
	}
}
