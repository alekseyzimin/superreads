/***** This code was generated by Yaggo. Do not edit ******/

#ifndef __CREATE_K_UNITIGS_ARGS_HPP__
#define __CREATE_K_UNITIGS_ARGS_HPP__

#include <yaggo.hpp>

class create_k_unitigs_args {
public:
  bool                           both_strands_flag;
  uint32_t                       threads_arg;
  bool                           threads_given;
  bool                           verbose_flag;
  yaggo::string                  prefix_arg;
  bool                           prefix_given;
  bool                           counts_flag;
  uint64_t                       min_len_arg;
  bool                           min_len_given;
  uint32_t                       min_cov_arg;
  bool                           min_cov_given;
  uint32_t                       min_cont_arg;
  bool                           min_cont_given;
  bool                           cont_on_low_flag;
  uint64_t                       low_stretch_arg;
  bool                           low_stretch_given;
  bool                           progress_flag;
  bool                           gzip_flag;
  const char *                   start_arg;
  bool                           start_given;
  bool                           no_load_flag;
  const char *                   file_arg;

  enum {
    USAGE_OPT = 1000,
    FULL_HELP_OPT,
    CONT_ON_LOW_OPT,
    LOW_STRETCH_OPT,
    NO_LOAD_OPT
  };

  create_k_unitigs_args() : 
    both_strands_flag(false),
    threads_arg(1), threads_given(false),
    verbose_flag(false),
    prefix_arg("k_unitigs"), prefix_given(false),
    counts_flag(false),
    min_len_arg(), min_len_given(false),
    min_cov_arg(2), min_cov_given(false),
    min_cont_arg(3), min_cont_given(false),
    cont_on_low_flag(false),
    low_stretch_arg(3), low_stretch_given(false),
    progress_flag(false),
    gzip_flag(false),
    start_arg(""), start_given(false),
    no_load_flag(false)
  { }

  create_k_unitigs_args(int argc, char* argv[]) :
    both_strands_flag(false),
    threads_arg(1), threads_given(false),
    verbose_flag(false),
    prefix_arg("k_unitigs"), prefix_given(false),
    counts_flag(false),
    min_len_arg(), min_len_given(false),
    min_cov_arg(2), min_cov_given(false),
    min_cont_arg(3), min_cont_given(false),
    cont_on_low_flag(false),
    low_stretch_arg(3), low_stretch_given(false),
    progress_flag(false),
    gzip_flag(false),
    start_arg(""), start_given(false),
    no_load_flag(false)
  { parse(argc, argv); }

  void parse(int argc, char* argv[]) {
    static struct option long_options[] = {
      {"both-strands", 0, 0, 'C'},
      {"threads", 1, 0, 't'},
      {"verbose", 0, 0, 'v'},
      {"prefix", 1, 0, 'o'},
      {"counts", 0, 0, 'c'},
      {"min-len", 1, 0, 'l'},
      {"min-cov", 1, 0, 'm'},
      {"min-cont", 1, 0, 'M'},
      {"cont-on-low", 0, 0, CONT_ON_LOW_OPT},
      {"low-stretch", 1, 0, LOW_STRETCH_OPT},
      {"progress", 0, 0, 'p'},
      {"gzip", 0, 0, 'g'},
      {"start", 1, 0, 's'},
      {"no-load", 0, 0, NO_LOAD_OPT},
      {"help", 0, 0, 'h'},
      {"full-help", 0, 0, FULL_HELP_OPT},
      {"usage", 0, 0, USAGE_OPT},
      {"version", 0, 0, 'V'},
      {0, 0, 0, 0}
    };
    static const char *short_options = "hVCt:vo:cl:m:M:pgs:";

    std::string err;
#define CHECK_ERR(type,val,which) if(!err.empty()) { std::cerr << "Invalid " #type " '" << val << "' for [" which "]: " << err << "\n"; exit(1); }
    while(true) { 
      int index = -1;
      int c = getopt_long(argc, argv, short_options, long_options, &index);
      if(c == -1) break;
      switch(c) {
      case ':': 
        std::cerr << "Missing required argument for "
                  << (index == -1 ? std::string(1, (char)optopt) : std::string(long_options[index].name))
                  << std::endl;
        exit(1);
      case 'h':
        std::cout << usage() << "\n\n" << help() << std::endl;
        exit(0);
      case USAGE_OPT:
        std::cout << usage() << "\nUse --help for more information." << std::endl;
        exit(0);
      case 'V':
        print_version();
        exit(0);
      case '?':
        std::cerr << "Use --usage or --help for some help\n";
        exit(1);
      case FULL_HELP_OPT:
        std::cout << usage() << "\n\n" << help() << "\n\n" << hidden() << std::endl;
        exit(0);
      case 'C':
        both_strands_flag = true;
        break;
      case 't':
        threads_given = true;
        threads_arg = yaggo::conv_uint<uint32_t>((const char *)optarg, err, false);
        CHECK_ERR(uint32_t, optarg, "-t, --threads=uint32")
        break;
      case 'v':
        verbose_flag = true;
        break;
      case 'o':
        prefix_given = true;
        prefix_arg.assign(optarg);
        break;
      case 'c':
        counts_flag = true;
        break;
      case 'l':
        min_len_given = true;
        min_len_arg = yaggo::conv_uint<uint64_t>((const char *)optarg, err, false);
        CHECK_ERR(uint64_t, optarg, "-l, --min-len=k+1")
        break;
      case 'm':
        min_cov_given = true;
        min_cov_arg = yaggo::conv_uint<uint32_t>((const char *)optarg, err, false);
        CHECK_ERR(uint32_t, optarg, "-m, --min-cov=uint32")
        break;
      case 'M':
        min_cont_given = true;
        min_cont_arg = yaggo::conv_uint<uint32_t>((const char *)optarg, err, false);
        CHECK_ERR(uint32_t, optarg, "-M, --min-cont=uint32")
        break;
      case CONT_ON_LOW_OPT:
        cont_on_low_flag = true;
        break;
      case LOW_STRETCH_OPT:
        low_stretch_given = true;
        low_stretch_arg = yaggo::conv_uint<uint64_t>((const char *)optarg, err, false);
        CHECK_ERR(uint64_t, optarg, "    --low-stretch=uint64")
        break;
      case 'p':
        progress_flag = true;
        break;
      case 'g':
        gzip_flag = true;
        break;
      case 's':
        start_given = true;
        start_arg = optarg;
        break;
      case NO_LOAD_OPT:
        no_load_flag = true;
        break;
      }
    }

    // Parse arguments
    if(argc - optind != 1)
      error("Requires exactly 1 argument.");
    file_arg = argv[optind];
    ++optind;
  }

#define create_k_unitigs_args_USAGE "Usage: create_k_unitigs [options] file:path"
  const char * usage() const { return create_k_unitigs_args_USAGE; }
  void error(const char *msg) { 
    std::cerr << "Error: " << msg << "\n" << usage()
              << "\nUse --help for more information"
              << std::endl;
    exit(1);
  }

#define create_k_unitigs_args_HELP "Create k-unitigs (unipaths) from a Jellyfish k-mer database.\n\n" \
  "Options (default value in (), *required):\n" \
  " -C, --both-strands                       Both strands (false)\n" \
  " -t, --threads=uint32                     Number of threads (1)\n" \
  " -v, --verbose                            Be verbose (false)\n" \
  " -o, --prefix=string                      Output prefix (k_unitigs)\n" \
  " -c, --counts                             Output counts file as well (false)\n" \
  " -l, --min-len=k+1                        Minimum length of k-unitig to output\n" \
  " -m, --min-cov=uint32                     Minimum k-mer coverage to be considered (2)\n" \
  " -M, --min-cont=uint32                    Minimum k-mer coverage to continue (3)\n" \
  "     --cont-on-low                        Continue on unique low k-mer (count < m) (false)\n" \
  "     --low-stretch=uint64                 Max number of low k-mer (3)\n" \
  " -p, --progress                           Display progress (false)\n" \
  " -g, --gzip                               Gzip output files (false)\n" \
  "     --usage                              Usage\n" \
  " -h, --help                               This message\n" \
  "     --full-help                          Detailed help\n" \
  " -V, --version                            Version"

  const char * help() const { return create_k_unitigs_args_HELP; }
#define create_k_unitigs_args_HIDDEN "Hidden options:\n" \
  " -s, --start=string                       Starting k-mer\n" \
  "     --no-load                            Do not load hash upfront (false)"

  const char * hidden() const { return create_k_unitigs_args_HIDDEN; }
  void print_version(std::ostream &os = std::cout) const {
#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "0.0.0"
#endif
    os << PACKAGE_VERSION << "\n";
  }
  void dump(std::ostream &os = std::cout) {
    os << "both_strands_flag:" << both_strands_flag << "\n";
    os << "threads_given:" << threads_given << " threads_arg:" << threads_arg << "\n";
    os << "verbose_flag:" << verbose_flag << "\n";
    os << "prefix_given:" << prefix_given << " prefix_arg:" << prefix_arg << "\n";
    os << "counts_flag:" << counts_flag << "\n";
    os << "min_len_given:" << min_len_given << " min_len_arg:" << min_len_arg << "\n";
    os << "min_cov_given:" << min_cov_given << " min_cov_arg:" << min_cov_arg << "\n";
    os << "min_cont_given:" << min_cont_given << " min_cont_arg:" << min_cont_arg << "\n";
    os << "cont_on_low_flag:" << cont_on_low_flag << "\n";
    os << "low_stretch_given:" << low_stretch_given << " low_stretch_arg:" << low_stretch_arg << "\n";
    os << "progress_flag:" << progress_flag << "\n";
    os << "gzip_flag:" << gzip_flag << "\n";
    os << "start_given:" << start_given << " start_arg:" << start_arg << "\n";
    os << "no_load_flag:" << no_load_flag << "\n";
    os << "file_arg:" << file_arg << "\n";
  }
private:
};

#endif // __CREATE_K_UNITIGS_ARGS_HPP__"
