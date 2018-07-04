#include "testutil.hpp"
#include <nix.hpp>


std::vector<nix::DataType> dtypes = {
    nix::DataType::UInt8,
    nix::DataType::UInt16,
    nix::DataType::UInt32,
    nix::DataType::UInt64,
    nix::DataType::Int8,
    nix::DataType::Int16,
    nix::DataType::Int32,
    nix::DataType::Int64,
    nix::DataType::Float,
    nix::DataType::Double,
    nix::DataType::String,
    nix::DataType::Bool
};


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Please specify a nix file (and nothing else)" << std::endl;
        return 1;
    }
    std::string fname = argv[1];
    nix::File nf = nix::File::open(fname, nix::FileMode::Overwrite);

    auto block = nf.createBlock("blockyblock", "ablocktype of thing");
    block.definition("I am a test block");
    block.forceCreatedAt(1500001000);

    char name [5];
    nix::Group group;
    for (int idx = 0; idx < 1000; idx++) {
        sprintf(name, "da%03d", idx);
        block.createDataArray(name, "recordings", nix::DataType::Double, nix::NDSize{100, 100});
        std::cout << name << std::endl;
    }
    return 0;
}
