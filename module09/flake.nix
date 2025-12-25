{
  description = "My Universal Dev Environment";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
    # arion.url = "github:hercules-ci/arion";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
    # arion,
    ...
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = nixpkgs.legacyPackages.${system};

        # --- 📦 1. กำหนด Library ที่ต้องใช้ในโปรเจกต์นี้ ---
        libraries = with pkgs; [
          # [Graphics & Game]
          glfw
          mesa
          libglvnd
          wayland
          libxkbcommon
          xorg.libX11

          # [General Libs]
          glib
          gtk3
        ];

        # --- 🛠️ 2. กำหนดเครื่องมือ (Tools) ---
        tools = with pkgs; [
          # arion.packages.${system}.arion 
          pkgs.docker-compose
          # [C/C++]
          gcc
          clang # Compiler (มี iostream)
          clang-tools # LSP (clangd)
          gnumake
          cmake
          gdb # Debugger
          valgrind # Memory Check

          # [Python] (ถ้ามี)
          # python3
          # python3Packages.pip

          # [Misc]
          pkg-config # ตัวช่วยหา library
        ];
      in {
        devShells.default = pkgs.mkShell {
          # ใส่ของเข้าไป
          buildInputs = libraries;
          nativeBuildInputs = tools;

          # --- 🔥 3. ShellHook: หัวใจสำคัญของการแก้ Error ---
          shellHook = ''
            echo "🚀 Welcome to Nix DevShell: ${system}"

            # [FIX 1] ทำให้ Clangd/LSP หา <iostream> เจอ
            export CPATH="${pkgs.gcc.cc}/include/c++/${pkgs.gcc.version}:${pkgs.gcc.cc}/include/c++/${pkgs.gcc.version}/x86_64-unknown-linux-gnu:$CPATH"
            export CPLUS_INCLUDE_PATH=$CPATH

            # [FIX 2] ทำให้โปรแกรมหา Library เจอตอนรัน (แก้ Segfault)
            export LD_LIBRARY_PATH=${pkgs.lib.makeLibraryPath libraries}:$LD_LIBRARY_PATH

            # [FIX 3] แก้ GDK/GTK/Wayland Error (ถ้าทำ App กราฟิก)
            export XDG_DATA_DIRS=${pkgs.gsettings-desktop-schemas}/share/gsettings-schemas/${pkgs.gsettings-desktop-schemas.name}:${pkgs.gtk3}/share/gsettings-schemas/${pkgs.gtk3.name}:$XDG_DATA_DIRS
          '';
        };
      }
    );
}
