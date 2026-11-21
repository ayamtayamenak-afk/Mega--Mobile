#include <Geode/Geode.hpp>

using namespace geode::prelude;

class MegaPopup : public Popup<> {
protected:
    bool setup() override {
        this->setTitle("MEGA MOBILE");

        auto info = CCLabelBMFont::create(
            "Welcome to Mega Mobile!",
            "bigFont.fnt"
        );
        info->setScale(0.45f);
        info->setPosition({m_size.width / 2, m_size.height - 65});
        m_mainLayer->addChild(info);

        auto menu = CCMenu::create();
        menu->setPosition({m_size.width / 2, m_size.height / 2 - 10});
        menu->setContentSize({m_size.width - 30, 100});
        m_mainLayer->addChild(menu);

        addButton(menu, "Gameplay", menu_selector(MegaPopup::gameplay));
        addButton(menu, "Player", menu_selector(MegaPopup::player));
        addButton(menu, "Settings", menu_selector(MegaPopup::settings));

        return true;
    }

    void addButton(CCMenu* menu, const char* text,
                   SEL_MenuHandler callback) {
        auto label = CCLabelBMFont::create(text, "goldFont.fnt");
        label->setScale(0.65f);

        auto button = CCMenuItemLabel::create(
            label, this, callback
        );

        menu->addChild(button);
    }

    void gameplay(CCObject*) {
        FLAlertLayer::create(
            "Gameplay",
            "Mega Mobile Gameplay tab",
            "Close"
        )->show();
    }

    void player(CCObject*) {
        FLAlertLayer::create(
            "Player",
            "Mega Mobile Player tab",
            "Close"
        )->show();
    }

    void settings(CCObject*) {
        FLAlertLayer::create(
            "Settings",
            "Mega Mobile Settings tab",
            "Close"
        )->show();
    }
};

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
            menu_selector(MegaMobileMenu::openMega)
        );

        auto menu = CCMenu::create();
        menu->addChild(button);
        menu->setPosition({220, 80});

        this->addChild(menu);

        return true;
    }

    void openMega(CCObject*) {
        MegaPopup::create()->show();
    }
};
