# Mega Mobile

**Mega Mobile** adalah fondasi proyek mod Geode khusus Android 64-bit untuk
Geometry Dash. Target game pada manifest disetel ke `2.208` sesuai permintaan.

## Status saat ini

- [x] Metadata Geode dan CMake project
- [x] Target Android saja
- [x] Entry point Geode dan hook MenuLayer
- [x] Tombol MEGA di menu utama
- [x] Panel informasi kategori
- [ ] Toggle cheat dan hook gameplay
- [ ] Sistem macro/replay
- [ ] Overlay status real-time
- [ ] AI Clipsy dengan layanan rekomendasi
- [ ] Pengujian di perangkat Android

Panel saat ini adalah kerangka UI awal, bukan implementasi cheat lengkap.
Setiap fitur gameplay perlu dibuat dan diuji terpisah terhadap versi game
dan SDK Geode yang dipakai. Fitur yang berpotensi merusak progres/level
sebaiknya diuji di level lokal atau Practice terlebih dahulu.

## Build Android 64-bit

1. Pasang Geode CLI, Android NDK, dan siapkan environment `ANDROID_NDK_ROOT`.
2. Dari folder proyek, jalankan:

   ```sh
   geode sdk install-binaries -p android64
   geode build -p android64
   ```

3. Jika berhasil, paket `.geode` akan berada di folder `build-android64`.
4. Salin paket ke folder mods Geode di perangkat Android.

## Catatan versi

Manifest menggunakan versi GD `2.208` seperti yang disebutkan. Dokumentasi
dan template Geode terbaru sering menggunakan `2.2081`. Jika versi yang
ditampilkan oleh instalasi game kamu sebenarnya `2.2081`, ubah nilai
`gd.android` di `mod.json` menjadi `2.2081` sebelum build. Versi SDK Geode
yang dipakai juga harus cocok dengan instalasi Geode kamu.
