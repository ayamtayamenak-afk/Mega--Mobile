# Build Mega Mobile menjadi .geode melalui GitHub

Workflow sudah disiapkan di `.github/workflows/build-android64.yml`.

## Dari HP Android

1. Ekstrak `Mega-Mobile-Geode-Android64.zip`.
2. Buka GitHub dan buat repository baru, misalnya `Mega-Mobile`.
3. Upload seluruh isi folder proyek ke repository (pastikan folder `.github`
   ikut ter-upload; beberapa file manager menyembunyikan folder yang diawali titik).
4. Buka tab **Actions** pada repository.
5. Pilih **Build Mega Mobile (Android 64-bit)**.
6. Tekan **Run workflow**. Workflow juga berjalan otomatis saat push ke `main`.
7. Tunggu sampai job hijau / **Success**.
8. Buka hasil run, cari bagian **Artifacts**, lalu download
   `Mega-Mobile-Android64`.
9. Ekstrak artifact ZIP tersebut. Di dalamnya ada file berakhiran `.geode`.

## Pasang ke Geometry Dash

Pindahkan file `.geode` ke folder mods Geode Android, biasanya:

`/storage/emulated/0/Android/media/com.geode.launcher/game/geode/mods/`

Buka ulang Geometry Dash / Geode Launcher.

## Jika build gagal

- Buka run di tab Actions lalu buka langkah yang merah.
- Pastikan semua file proyek di-upload, termasuk `.github/workflows/build-android64.yml`.
- Baca pesan error pertama yang muncul; error berikutnya sering hanya efek lanjutan.
- Cocokkan `gd.android` di `mod.json` dengan versi game yang benar-benar terpasang.
- Workflow ini mengambil Geode SDK terbaru; bila versi SDK tidak mendukung versi game
  yang dipakai, perlu pin SDK/bindings yang sesuai.

**Penting:** GitHub Actions hanya mengompilasi source. Source saat ini baru
kerangka tombol/menu awal Mega Mobile; daftar cheat, macro, dan AI Clipsy
belum menjadi fitur aktif. Build sukses tidak berarti semua fitur roadmap
sudah tersedia.
