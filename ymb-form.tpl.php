<div class='ymb-form'>
  <p><?php print $ymb_form['description']; ?></p>
  <form method='POST' action='https://money.yandex.ru/quickpay/confirm.xml'>
    <div class='form-item form-type-textfield form-item-sum'>
      <label for='edit-sum--<?php print $ymb_form['bid']; ?>'>
        <?php print t('Amount'); ?>
        <span class='form-required' title='<?php print t('This field is required.'); ?>'>*</span>
      </label>
      <input id='edit-sum--<?php print $ymb_form['bid']; ?>' name='sum' value='<?php print $ymb_form['sum']; ?>' data-type='number' class='form-text required'>
    </div>

    <div class='form-item form-type-radios form-item-payment-type'>
      <div id='edit-payment-type--<?php print $ymb_form['bid']; ?>' class='form-radios'>
        <div class='form-item form-type-radio form-item-payment-type'>
          <input id='edit-payment-type-pc--<?php print $ymb_form['bid']; ?>' type='radio' name='paymentType' value='PC' class='form-radio'>
          <label class='option' for='edit-payment-type-pc--<?php print $ymb_form['bid']; ?>'>
            <?php print t('Yandex.Money'); ?>
          </label>
        </div>

        <div class='form-item form-type-radio form-item-payment-type'>
          <input id='edit-payment-type-ac--<?php print $ymb_form['bid']; ?>' type='radio' name='paymentType' value='AC' class='form-radio'>
          <label class='option' for='edit-payment-type-ac--<?php print $ymb_form['bid']; ?>'>
            <?php print t('Bank card'); ?>
          </label>
        </div>
      </div>
    </div>


    <div class='form-actions form-wrapper' id='edit-actions--<?php print $ymb_form['bid']; ?>'>
      <input id='edit-submit--<?php print $ymb_form['bid']; ?>' type='submit' value='<?php print t('Pay'); ?>' class='form-submit'>
    </div>
    <input type='hidden' name='receiver' value='<?php print $ymb_form['receiver']; ?>'>
    <input type='hidden' name='targets' value='<?php print $ymb_form['target']; ?>'>
    <input type='hidden' name='quickpay-form' value='donate'>
    <input type='hidden' name='successURL' value='<?php print $ymb_form['url']; ?>'>
  </form>
</div>
