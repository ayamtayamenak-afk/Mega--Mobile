#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MegaMobileMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto label = CCLabelBMFont::create(
            "MEGA",
            "goldFont.fnt"
        );

        label->setScale(0.65f);

        auto button = CCMenuItemLabel::create(
            label,
            this,
            menu_selector(MegaMobileMenu::openMenu)
        );

        auto menu = CCMenu::create();
        menu->addChild(button);
        menu->setPosition({220, 80});

        this->addChild(menu);

        return true;
    }

    void openMenu(CCObject*) {
        FLAlertLayer::create(
            "MEGA MOBILE",
            "Welcome to Mega Mobile!\n\n"
            "Gameplay\n"
            "Player\n"
            "Settings\n\n"
            "Mega Mobile Android Edition",
            "CLOSE"
        )->show();
    }
};
