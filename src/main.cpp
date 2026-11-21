#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <algorithm>

using namespace geode::prelude;

class MegaFloatingButton : public CCLayer {
    CCLabelBMFont* m_button = nullptr;
    CCPoint m_startTouch;
    CCPoint m_startPosition;
    bool m_dragged = false;

public:
    static MegaFloatingButton* create() {
        auto ret = new MegaFloatingButton();
        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool init() override {
        if (!CCLayer::init())
            return false;

        m_button = CCLabelBMFont::create("MEGA", "goldFont.fnt");
        m_button->setScale(0.7f);
        m_button->setPosition({100, 180});
        addChild(m_button);

        setTouchEnabled(true);
        setTouchPriority(-500);
        return true;
    }

    void registerWithTouchDispatcher() override {
        CCTouchDispatcher::get()->addTargetedDelegate(
            this, -500, true
        );
    }

    bool ccTouchBegan(CCTouch* touch, CCEvent*) override {
        auto point = convertToNodeSpace(touch->getLocation());

        if (!m_button->boundingBox().containsPoint(point))
            return false;

        m_startTouch = touch->getLocation();
        m_startPosition = m_button->getPosition();
        m_dragged = false;
        return true;
    }

    void ccTouchMoved(CCTouch* touch, CCEvent*) override {
        auto delta = touch->getLocation() - m_startTouch;

        if (delta.getLength() > 10)
            m_dragged = true;

        if (m_dragged) {
            auto win = CCDirector::get()->getWinSize();
            auto pos = m_startPosition + delta;

            pos.x = std::clamp(pos.x, 30.f, win.width - 30.f);
            pos.y = std::clamp(pos.y, 30.f, win.height - 30.f);

            m_button->setPosition(pos);
        }
    }

    void ccTouchEnded(CCTouch*, CCEvent*) override {
        if (!m_dragged)
            openMenu();
    }

    void ccTouchCancelled(CCTouch*, CCEvent*) override {}

    void openMenu() {
        FLAlertLayer::create(
            "MEGA MOBILE",
            "Gameplay\n"
            "Player\n"
            "Settings\n"
            "Tools\n\n"
            "Mega Mobile",
            "CLOSE"
        )->show();
    }
};

class $modify(MegaMobileMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto floating = MegaFloatingButton::create();
        this->addChild(floating, 999);

        return true;
    }
};

class $modify(MegaMobilePlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        auto floating = MegaFloatingButton::create();
        this->addChild(floating, 999);

        return true;
    }
};
