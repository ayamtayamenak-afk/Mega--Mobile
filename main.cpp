#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

// Mega Mobile is intentionally Android-only. Build with -p android64.
#if defined(GEODE_IS_ANDROID)

class $modify(MegaMobileMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto menu = CCMenu::create();
        menu->setPosition({0.f, 0.f});

        auto label = CCLabelBMFont::create("MEGA", "goldFont.fnt");
        label->setScale(0.48f);

        auto button = CCMenuItemSpriteExtra::create(
            label,
            this,
            menu_selector(MegaMobileMenuLayer::onMegaMobile)
        );
        button->setPosition({winSize.width - 42.f, 54.f});
        menu->addChild(button);

        this->addChild(menu, 1000);
        return true;
    }

    void onMegaMobile(CCObject*) {
        FLAlertLayer::create(
            "MEGA MOBILE",
            "<cy>Android 64-bit build foundation</c>\n\n"
            "<cg>GAMEPLAY</c>\n"
            "Noclip, Speedhack, Freeze Player, Jump Hack, Auto Clicker\n\n"
            "<cg>MACRO / REPLAY</c>\n"
            "Recorder, Replay Status, Practice helpers\n\n"
            "<cg>PERFORMANCE</c>\n"
            "FPS options, Frame Stepper, Low Detail\n\n"
            "<cg>VISUAL</c>\n"
            "Hitboxes, trail/effect controls, layout view\n\n"
            "<cg>CREATOR / EDITOR</c>\n"
            "Editor utilities and bypass research\n\n"
            "<cg>OVERLAY</c>\n"
            "FPS, CPS, percentage, session information\n\n"
            "<cg>AI CLIPSY</c>\n"
            "Recommendation assistant concept\n\n"
            "<cy>Catatan:</c> Ini adalah fondasi proyek. Tombol menu sudah dibuat, "
            "tetapi toggle cheat, macro engine, AI online, dan hook gameplay "
            "belum diimplementasikan. Jangan anggap fitur-fitur tersebut aktif.",
            "TUTUP"
        )->show();
    }
};

#else
#error "Mega Mobile hanya mendukung target Android. Gunakan: geode build -p android64"
#endif
