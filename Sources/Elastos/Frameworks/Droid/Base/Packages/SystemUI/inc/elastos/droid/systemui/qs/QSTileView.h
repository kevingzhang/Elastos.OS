//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_SYSTEMUI_QS_QSTILEVIEW_H__
#define __ELASTOS_DROID_SYSTEMUI_QS_QSTILEVIEW_H__

#include "_Elastos.Droid.SystemUI.h"
#include "Elastos.Droid.Graphics.h"
#include "Elastos.Droid.Widget.h"
#include <elastos/droid/os/Handler.h>
#include <elastos/droid/view/ViewGroup.h>
#include <elastos/core/Object.h>

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::Res::IConfiguration;
using Elastos::Droid::Graphics::ITypeface;
using Elastos::Droid::Graphics::Drawable::IRippleDrawable;
using Elastos::Droid::Os::Handler;
using Elastos::Droid::Os::IMessage;
using Elastos::Droid::View::IViewOnClickListener;
using Elastos::Droid::View::ViewGroup;
using Elastos::Droid::Widget::ITextView;
using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Qs {

/** View that represents a standard quick settings tile. **/
class QSTileView
    : public ViewGroup
    , public IQSTileView
{
private:
    class H: public Handler
    {
    public:
        TO_STRING_IMPL("QSTileView::H")

        H(
            /* [in] */ QSTileView* host);

        // @Override
        CARAPI HandleMessage(
            /* [in] */ IMessage* msg);

    public:
        static const Int32 STATE_CHANGED;
        QSTileView* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    QSTileView();

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI SetDual(
        /* [in] */ Boolean dual);

    CARAPI Init(
        /* [in] */ IViewOnClickListener* clickPrimary,
        /* [in] */ IViewOnClickListener* clickSecondary);

    CARAPI OnStateChanged(
        /* [in] */ IQSTileState* state);

protected:
    // @Override
    CARAPI OnConfigurationChanged(
        /* [in] */ IConfiguration* newConfig);

    virtual CARAPI_(AutoPtr<IView>) CreateIcon();

    // @Override
    CARAPI OnMeasure(
        /* [in] */ Int32 widthMeasureSpec,
        /* [in] */ Int32 heightMeasureSpec);

    // @Override
    CARAPI OnLayout(
        /* [in] */ Boolean changed,
        /* [in] */ Int32 l,
        /* [in] */ Int32 t,
        /* [in] */ Int32 r,
        /* [in] */ Int32 b);

    virtual CARAPI HandleStateChanged(
        /* [in] */ IQSTileState* state);

private:
    CARAPI_(void) UpdateTopPadding();

    CARAPI_(void) RecreateLabel();

    CARAPI_(void) SetRipple(
        /* [in] */ IRippleDrawable* tileBackground);

    CARAPI_(AutoPtr<IDrawable>) GetTileBackground();

    CARAPI_(AutoPtr<IView>) LabelView();

    static CARAPI_(Int32) Exactly(
        /* [in] */ Int32 size);

    CARAPI_(void) UpdateRippleSize(
        /* [in] */ Int32 width,
        /* [in] */ Int32 height);

    static CARAPI_(void) Layout(
        /* [in] */ IView* child,
        /* [in] */ Int32 left,
        /* [in] */ Int32 top);

    static CARAPI_(AutoPtr<ITypeface>) InitStatic();

private:
    static AutoPtr<ITypeface> CONDENSED;

    AutoPtr<IView> mIcon;
    AutoPtr<IView> mDivider;
    AutoPtr<H> mHandler;
    Int32 mIconSizePx;
    Int32 mTileSpacingPx;
    Int32 mTilePaddingTopPx;
    Int32 mTilePaddingBelowIconPx;
    Int32 mDualTileVerticalPaddingPx;
    AutoPtr<IView> mTopBackgroundView;

    AutoPtr<ITextView> mLabel;
    AutoPtr<IQSDualTileLabel> mDualLabel;
    Boolean mDual;
    AutoPtr<IViewOnClickListener> mClickPrimary;
    AutoPtr<IViewOnClickListener> mClickSecondary;
    AutoPtr<IRippleDrawable> mRipple;
};

} // namespace Qs
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SYSTEMUI_QS_QSTILEVIEW_H__
