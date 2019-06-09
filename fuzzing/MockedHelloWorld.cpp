#include "App.h"

#include "helpers.h"

/* This function pushes data to the uSockets mock */
extern void us_loop_read_mocked_data(struct us_loop *loop, char *data, unsigned int size);

/* HelloWorld */
auto app = uWS::App().get("/*", [](auto *res, auto *req) {
	res->end("Hello world!");
}).listen(9001, [](auto *token) {
    if (token) {
        std::cout << "Listening on port " << 9001 << std::endl;
    }
});

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {

    us_loop_read_mocked_data((struct us_loop *) uWS::Loop::get(), (char *) makePadded(data, size), size);

    return 0;
}