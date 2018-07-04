#include <nix.hpp>


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
    block = nf.getBlock(0);
    // Alias RangeDimension
    auto da = block.createDataArray("alias da", "dimticks", nix::DataType::Int32, nix::NDSize{24});
    return 0;
}
