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

#include "Elastos.Droid.View.h"
#include "Elastos.Droid.Widget.h"
#include "elastos/droid/preference/SeekBarDialogPreference.h"
#include "elastos/droid/R.h"

using Elastos::Droid::Widget::IImageView;
using Elastos::Droid::R;

namespace Elastos {
namespace Droid {
namespace Preference {

const String SeekBarDialogPreference::TAG("SeekBarDialogPreference");

CAR_INTERFACE_IMPL(SeekBarDialogPreference, DialogPreference, ISeekBarDialogPreference)

SeekBarDialogPreference::SeekBarDialogPreference()
{
}

ECode SeekBarDialogPreference::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IAttributeSet* attrs,
    /* [in] */ Int32 defStyleAttr,
    /* [in] */ Int32 defStyleRes)
{
    DialogPreference::constructor(context, attrs, defStyleAttr, defStyleRes);
    SetDialogLayoutResource(R::layout::seekbar_dialog);
    CreateActionButtons();

    // Steal the XML dialogIcon attribute's value
    GetDialogIcon((IDrawable**)&mMyIcon);
    SetDialogIcon((IDrawable*)NULL);
    return NOERROR;
}

ECode SeekBarDialogPreference::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IAttributeSet* attrs,
    /* [in] */ Int32 defStyleAttr)
{
    return constructor(context, attrs, defStyleAttr, 0);
}

ECode SeekBarDialogPreference::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IAttributeSet* attrs)
{
    return constructor(context, attrs, R::attr::dialogPreferenceStyle);
}

ECode SeekBarDialogPreference::constructor(
    /* [in] */ IContext* context)
{
    return constructor(context, NULL);
}

ECode SeekBarDialogPreference::CreateActionButtons()
{
    SetPositiveButtonText(R::string::ok);
    SetNegativeButtonText(R::string::cancel);
    return NOERROR;
}

ECode SeekBarDialogPreference::OnBindDialogView(
    /* [in] */ IView* view)
{
    DialogPreference::OnBindDialogView(view);

    AutoPtr<IView> icon;
    view->FindViewById(R::id::icon, (IView**)&icon);
    IImageView* iconView = IImageView::Probe(icon);
    if (mMyIcon != NULL) {
        iconView->SetImageDrawable(mMyIcon);
    }
    else {
        AutoPtr<IView> v = IView::Probe(iconView);
        v->SetVisibility(IView::GONE);
    }
    return NOERROR;
}

ECode SeekBarDialogPreference::GetSeekBar(
    /* [in] */ IView* dialogView,
    /* [out] */ ISeekBar** bar)
{
    VALIDATE_NOT_NULL(bar)
    AutoPtr<IView> v;
    dialogView->FindViewById(R::id::seekbar, (IView**)&v);
    AutoPtr<ISeekBar> seekBar = ISeekBar::Probe(v);
    *bar = seekBar;
    REFCOUNT_ADD(*bar)
    return NOERROR;
}

}
}
}

