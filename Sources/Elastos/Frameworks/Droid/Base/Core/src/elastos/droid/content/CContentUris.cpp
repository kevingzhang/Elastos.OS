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

#include "Elastos.Droid.Net.h"
#include "elastos/droid/content/CContentUris.h"
#include <elastos/core/StringUtils.h>

using Elastos::Core::StringUtils;

namespace Elastos {
namespace Droid {
namespace Content {

CAR_INTERFACE_IMPL(CContentUris, Object, IContentUris)

CAR_SINGLETON_IMPL(CContentUris)

ECode CContentUris::ParseId(
    /* [in] */ IUri* contentUri,
    /* [out] */ Int64* id)
{
    VALIDATE_NOT_NULL(id)
    *id = -1;
    VALIDATE_NOT_NULL(contentUri)

    String last;
    FAIL_RETURN(contentUri->GetLastPathSegment(&last));
    if (last.IsNull()) {
        *id = -1;
        return NOERROR;
    }
    return StringUtils::Parse(last, id);
}

ECode CContentUris::AppendId(
    /* [in] */ IUriBuilder* builder,
    /* [in] */ Int64 id)
{
    VALIDATE_NOT_NULL(builder)
    return builder->AppendEncodedPath(StringUtils::ToString(id));
}

ECode CContentUris::WithAppendedId(
    /* [in] */ IUri* contentUri,
    /* [in] */ Int64 id,
    /* [out] */ IUri** newUri)
{
    VALIDATE_NOT_NULL(newUri)
    *newUri = NULL;

    VALIDATE_NOT_NULL(contentUri)
    AutoPtr<IUriBuilder> ub;
    FAIL_RETURN(contentUri->BuildUpon((IUriBuilder**)&ub));
    FAIL_RETURN(AppendId(ub, id));
    return ub->Build(newUri);
}

}
}
}

