fn main() {
    // check_arch();
    cxx_build::bridge("src/main.rs")
        .file("src/gmtrade_def.cc")
        .flag_if_supported("-std=c++14")
        .compile("gmtrade-rs");

    // add_search_path();
    // add_llvm_path();
    // println!("cargo:rustc-link-lib=gmtrade");
    
    println!("cargo:rerun-if-changed=include/gmtrade_csdk.h");
    println!("cargo:rerun-if-changed=include/gmtrade_def.h");
    println!("cargo:rerun-if-changed=include/gmtrade.h");
    
    

    println!("cargo:rerun-if-changed=src/main.rs");

}
// #[cfg(target_os = "windows")]
// fn add_search_path() {
//     for path in std::env::var("PATH").unwrap_or_else(|_| "".to_string()).split(";") {
//         if path.trim().len() == 0 {
//             continue;
//         }
//         println!("cargo:rustc-link-search={}", path);
//     }
// }

// #[cfg(target_arch = "x86_64")]
// fn check_arch() {}


// fn add_llvm_path() {
//     if let Some(llvm_config_path) = option_env!("LLVM_CONFIG_PATH") {
//         println!("cargo:rustc-env=LLVM_CONFIG_PATH={}", llvm_config_path);
//     }
// }